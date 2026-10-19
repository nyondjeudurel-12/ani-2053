#include <NKNetwork/NKNetwork.h>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <atomic>

using namespace nkentseu;

int main(int argc, char* argv[])
{
    // Vérifier l'argument fourni au programme.
    if (argc < 2)
    {
        std::cout << "Utilisation : parle serveur | client\n";
        return 1;
    }

    const std::string mode = argv[1];

    // Initialiser la plateforme réseau.
    NkSocket::PlatformInit();

    NkConnectionManager manager;

    std::atomic<bool> connected{false};
    NkPeerId peerId{};

    // Callback appelé lorsqu'un pair se connecte.
    manager.onPeerConnected = [&](NkPeerId peer)
    {
        peerId = peer;
        connected.store(true);

        std::cout << "Pair connecte : " << peer.value << '\n';
    };
    // MODE SERVEUR
    if (mode == "serveur")
    {
        const auto result = manager.StartServer(7777, 8);

        if (result != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Erreur : impossible de demarrer le serveur.\n";
            manager.Shutdown();
            return 1;
        }

        std::cout << "Serveur demarre sur le port 7777.\n";
        std::cout << "En attente d'un client...\n";

        bool messageRecu = false;

        while (!messageRecu)
        {
            NkVector<NkReceiveMsg> messages;
            manager.DrainAll(messages);

            for (const auto& message : messages)
            {
                std::string texte(
                    reinterpret_cast<const char*>(message.data),
                    message.size
                );

                std::cout << "Message recu de "
                          << message.from.value
                          << " : "
                          << texte
                          << '\n';

                messageRecu = true;
            }

            std::this_thread::sleep_for(
                std::chrono::milliseconds(10)
            );
        }

        manager.Shutdown();
    }
    // MODE CLIENT
    else if (mode == "client")
    {
        const auto result = manager.Connect(
            NkAddress("127.0.0.1", 7777)
        );

        if (result != NkNetResult::NK_NET_OK)
        {
            std::cerr << "Erreur : impossible de se connecter au serveur.\n";
            manager.Shutdown();
            return 1;
        }

        std::cout << "Connexion au serveur en cours...\n";

        // Attendre que le callback confirme la connexion.
        const auto debut = std::chrono::steady_clock::now();

        while (!connected.load())
        {
            const auto maintenant = std::chrono::steady_clock::now();

            if (maintenant - debut > std::chrono::seconds(15))
            {
                std::cerr << "Delai depasse : connexion non confirmee.\n";
                manager.Shutdown();
                return 1;
            }

            std::this_thread::sleep_for(
                std::chrono::milliseconds(10)
            );
        }

        const std::string texte = "Bonjour serveur !";

        const auto envoi = manager.SendTo(
            peerId,
            reinterpret_cast<const uint8*>(texte.c_str()),
            static_cast<uint32>(texte.size())
        );

        if (envoi == NkNetResult::NK_NET_OK)
        {
            std::cout << "Message envoye : " << texte << '\n';
        }
        else
        {
            std::cerr << "Erreur lors de l'envoi du message.\n";
        }

        manager.Shutdown();
    }

    else
    {
        std::cerr << "Mode inconnu. Utilise serveur ou client.\n";
        manager.Shutdown();
        return 1;
    }

    return 0;
}

