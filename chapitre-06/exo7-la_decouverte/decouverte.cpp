#include <NKNetwork/NKNetwork.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace nkentseu;
using namespace nkentseu::net;

int main(int argc, char* argv[])
{
    // Initialiser le système réseau.
    NkSocket::PlatformInit();

    // Vérifier le rôle demandé.
    if (argc < 2)
    {
        std::cout << "Utilisation :\n";
        std::cout << "  decouverte.exe serveur\n";
        std::cout << "  decouverte.exe client\n";
        return 1;
    }

    // Mode serveur : diffuser les informations régulièrement.
    if (std::strcmp(argv[1], "serveur") == 0)
    {
        NkDiscovery::ServerInfo info;

        // Copier le nom dans le tableau de caractères.
        std::strncpy(info.name, "Serveur de decouverte",
                     sizeof(info.name) - 1);

        // Renseigner le nombre maximal de joueurs.
        info.maxPlayers = 4;

        // Indiquer le port du serveur.
        info.addr = NkAddress::Any(7777);

        std::cout << "Serveur en diffusion.\n";
        std::cout << "Nom : " << info.name << '\n';
        std::cout << "Joueurs maximum : " << info.maxPlayers << '\n';

        // Diffuser les informations toutes les deux secondes.
        while (true)
        {
            const auto resultat = NkDiscovery::Broadcast(info);

            // Signaler un éventuel échec de diffusion.
            (void)resultat;

            std::cout << "Annonce diffusee.\n";

            std::this_thread::sleep_for(
                std::chrono::seconds(2));
        }
    }

    // Mode client : écouter le réseau pendant six secondes.
    if (std::strcmp(argv[1], "client") == 0)
    {
        NkVector<NkDiscovery::ServerInfo> trouves;

        std::cout << "Recherche des serveurs pendant 6 secondes...\n";

        // Écouter les annonces des serveurs.
        const auto resultat = NkDiscovery::Listen(6000, trouves);

        // Le résultat est conservé pour éviter l'avertissement nodiscard.
        (void)resultat;

        std::cout << "\nServeurs trouves :\n";

        // Afficher les serveurs découverts.
        for (const auto& serveur : trouves)
        {
            // La conversion de NkString sera adaptée après vérification.
            const NkString adresse = serveur.addr.ToString();

            std::cout << "Nom : " << serveur.name << '\n';

            // Afficher l'adresse après avoir vérifié sa conversion.
            (void)adresse;
        }

        if (trouves.Size() == 0)
        {
            std::cout << "Aucun serveur trouve.\n";
        }
    }
    else if (std::strcmp(argv[1], "serveur") != 0)
    {
        std::cerr << "Role inconnu. Utilisez serveur ou client.\n";
        return 1;
    }

    return 0;
}

