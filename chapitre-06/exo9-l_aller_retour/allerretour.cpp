#include <NKNetwork/NKNetwork.h>
#include <NKTime/NkChrono.h>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

using namespace nkentseu;

// Configuration du test
constexpr uint16 PORT = 7777;
constexpr uint32 NOMBRE_MESURES = 100;
constexpr float ALPHA = 0.125f;
constexpr double RTT_INITIAL = 100.0;
constexpr double DELAI_MAX_MS = 10000.0;

// Petite pause pour éviter de monopoliser le processeur.
void PetitePause()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

// MODE SERVEUR : reçoit les messages et les renvoie sans les modifier.

int LancerServeur()
{
    // Initialise le sous-système réseau.
    if (NkSocket::PlatformInit() != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : initialisation réseau impossible.\n";
        return 1;
    }

    NkConnectionManager serveur;

    // Démarre le serveur sur le port choisi.
    if (serveur.StartServer(PORT) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : impossible de démarrer le serveur.\n";
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "Serveur en attente sur le port " << PORT << "...\n";

    uint32 messagesRenvoies = 0;

    // Le serveur reste actif jusqu'à avoir renvoyé les 100 messages.
    while (serveur.IsRunning() &&
           messagesRenvoies < NOMBRE_MESURES)
    {
        NkVector<NkReceiveMsg> messages;

        // Récupère les messages disponibles.
        serveur.DrainAll(messages);

        for (const auto& message : messages)
        {
            // Ignore les messages vides ou trop grands.
            if (message.size == 0)
                continue;

            // Renvoie exactement les octets reçus à leur expéditeur.
            NkNetResult resultat = serveur.SendTo(
                message.from,
                message.data,
                message.size
            );

            if (resultat == NkNetResult::NK_NET_OK)
            {
                ++messagesRenvoies;
                std::cout << "Message renvoyé : "
                          << messagesRenvoies << "/"
                          << NOMBRE_MESURES << '\n';
            }
            else
            {
                std::cerr << "Erreur lors du renvoi du message.\n";
            }
        }

        PetitePause();
    }

    // Ferme proprement le gestionnaire réseau.
    serveur.Shutdown();
    NkSocket::PlatformShutdown();

    std::cout << "Serveur arrêté.\n";
    return 0;
}

// MODE CLIENT : effectue 100 mesures du temps aller-retour.

int LancerClient()
{
    // Initialise le sous-système réseau.
    if (NkSocket::PlatformInit() != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : initialisation réseau impossible.\n";
        return 1;
    }

    NkConnectionManager client;
    std::atomic<bool> connecte{false};

    // Ce callback indique que la connexion au serveur est établie.
    client.onPeerConnected = [&connecte](NkPeerId)
    {
        connecte.store(true);
    };

    // Connexion au serveur local : 127.0.0.1.
    if (client.Connect(NkAddress::Loopback(PORT)) != NkNetResult::NK_NET_OK)
    {
        std::cerr << "Erreur : connexion au serveur impossible.\n";
        client.Shutdown();
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "Connexion au serveur en cours...\n";

    // Attend la confirmation de connexion, avec un délai maximal.
    NkChrono attenteConnexion;

    while (!connecte.load())
    {
        if (attenteConnexion.Elapsed().ToMilliseconds() >= DELAI_MAX_MS)
        {
            std::cerr << "Erreur : délai de connexion dépassé.\n";
            client.Shutdown();
            NkSocket::PlatformShutdown();
            return 1;
        }

        PetitePause();
    }

    std::cout << "Connexion établie. Début des mesures.\n";

    std::vector<double> mesures;
    mesures.reserve(NOMBRE_MESURES);

    // Le lissage exponentiel commence à la valeur initiale demandée.
    double srtt = RTT_INITIAL;

    // Le client envoie un message, attend sa réponse, puis recommence.
    for (uint32 numero = 1; numero <= NOMBRE_MESURES; ++numero)
    {
        // Le numéro est transmis sous forme d'un entier de 32 bits.
        uint32 messageEnvoye = numero;
        bool reponseRecue = false;

        // Un nouveau chronomètre mesure ce trajet aller-retour.
        NkChrono chrono;

        // Envoie le numéro au serveur.
        NkNetResult resultat = client.SendTo(
            NkPeerId::Server(),
            reinterpret_cast<const uint8*>(&messageEnvoye),
            static_cast<uint32>(sizeof(messageEnvoye))
        );

        if (resultat != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Erreur d'envoi pour le message "
                      << numero << ".\n";

            client.Shutdown();
            NkSocket::PlatformShutdown();
            return 1;
        }

        // Attend la réponse contenant le même numéro.
        while (!reponseRecue)
        {
            NkVector<NkReceiveMsg> messages;
            client.DrainAll(messages);

            for (const auto& message : messages)
            {
                // Vérifie la taille avant de lire le numéro.
                if (message.size != sizeof(uint32))
                    continue;

                uint32 numeroRecu = 0;

                // Copie les octets reçus dans un entier.
                std::memcpy(
                    &numeroRecu,
                    message.data,
                    sizeof(numeroRecu)
                );

                // Ignore les réponses qui ne correspondent pas à la demande.
                if (numeroRecu == numero)
                {
                    reponseRecue = true;
                    break;
                }
            }

            // Évite d'attendre indéfiniment en cas de problème réseau.
            if (!reponseRecue &&
                chrono.Elapsed().ToMilliseconds() >= DELAI_MAX_MS)
            {
                std::cerr << "Délai dépassé pour le message "
                          << numero << ".\n";

                client.Shutdown();
                NkSocket::PlatformShutdown();
                return 1;
            }

            if (!reponseRecue)
                PetitePause();
        }

        // Mesure le temps écoulé entre l'envoi et la réception.
        double rtt = chrono.Elapsed().ToMilliseconds();
        mesures.push_back(rtt);

        // Met à jour le RTT lissé avec alpha = 0,125.
        srtt = (1.0 - ALPHA) * srtt + ALPHA * rtt;

        std::cout << "Mesure " << numero << "/"
                  << NOMBRE_MESURES << " : "
                  << rtt << " ms\n";
    }

    // Calcule la moyenne, le minimum et le maximum.
    double somme = 0.0;

    for (double mesure : mesures)
        somme += mesure;

    double moyenne = somme / mesures.size();

    double minimum = *std::min_element(
        mesures.begin(),
        mesures.end()
    );

    double maximum = *std::max_element(
        mesures.begin(),
        mesures.end()
    );

    // Écrit uniquement les 100 valeurs numériques dans mesures-rtt.txt.
    std::ofstream fichierMesures("mesures-rtt.txt");

    if (!fichierMesures)
    {
        std::cerr << "Erreur : impossible de créer mesures-rtt.txt.\n";
        client.Shutdown();
        NkSocket::PlatformShutdown();
        return 1;
    }

    for (double mesure : mesures)
        fichierMesures << mesure << '\n';

    fichierMesures.close();

    // Récupère l'estimation RTT du moteur pour la connexion au serveur.
   // Structure contenant les statistiques de connexion du moteur.
   nkentseu::net::NkConnectionStats statistiquesMoteur;
    double rttMoteur = 0.0;

    if (client.GetConnectionStats(
            NkPeerId::Server(),
            statistiquesMoteur))
    {
        rttMoteur = statistiquesMoteur.rttMs;
    }
    else
    {
        std::cerr << "Attention : statistiques moteur indisponibles.\n";
    }

    double ecart = std::abs(srtt - rttMoteur);

    // Produit le compte rendu avec les six rubriques demandées.
    std::ofstream fichierRTT("rtt.txt");

    if (!fichierRTT)
    {
        std::cerr << "Erreur : impossible de créer rtt.txt.\n";
        client.Shutdown();
        NkSocket::PlatformShutdown();
        return 1;
    }

    fichierRTT << "Moyenne : " << moyenne << " ms\n";
    fichierRTT << "Minimum : " << minimum << " ms\n";
    fichierRTT << "Maximum : " << maximum << " ms\n";
    fichierRTT << "Lissée : " << srtt << " ms\n";
    fichierRTT << "Moteur : " << rttMoteur << " ms\n";
    fichierRTT << "Écart : " << ecart << " ms. "
               << "La mesure manuelle chronomètre l'aller-retour complet "
               << "de chaque message. Le moteur estime le RTT à partir "
               << "de ses propres mécanismes de suivi et de lissage. "
               << "Les valeurs peuvent donc différer. Sur 127.0.0.1, "
               << "les échanges restent sur la même machine et ne "
               << "représentent pas les délais d'un véritable réseau.\n";

    fichierRTT.close();

    std::cout << "\nMesures terminées.\n";
    std::cout << "Moyenne : " << moyenne << " ms\n";
    std::cout << "Minimum : " << minimum << " ms\n";
    std::cout << "Maximum : " << maximum << " ms\n";
    std::cout << "Lissée : " << srtt << " ms\n";
    std::cout << "Moteur : " << rttMoteur << " ms\n";
    std::cout << "Fichiers générés : mesures-rtt.txt et rtt.txt\n";

    // Ferme la connexion et libère les ressources réseau.
    client.DisconnectAll("Fin des mesures");
    client.Shutdown();
    NkSocket::PlatformShutdown();

    return 0;
}

// Point d'entrée : choisir le mode serveur ou client avec un argument.

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Utilisation :\n";
        std::cout << "  allerretour.exe serveur\n";
        std::cout << "  allerretour.exe client\n";
        return 0;
    }

    if (std::strcmp(argv[1], "serveur") == 0)
        return LancerServeur();

    if (std::strcmp(argv[1], "client") == 0)
        return LancerClient();

    std::cerr << "Mode inconnu. Utilisez serveur ou client.\n";
    return 1;
}

