#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>

#include "NKNetwork/Transport/NkSocket.h"
#include "NKNetwork/Protocol/NkBitStream.h"

using namespace nkentseu;
using namespace nkentseu::net;

// Port de communication locale entre le client et le serveur.
constexpr uint16 PORT = 7777;

// État du joueur à transmettre.
struct EtatJoueur
{
bool vivant = true;
uint8 numero = 42;
float32 x = 123.456f;
float32 y = -78.912f;
float32 angle = 123.7f;
int32 sante = 87;
};

// Sérialise l'état du joueur avec les types complets.
uint32 EcrireComplet(uint8* buffer, uint32 capacite,
const EtatJoueur& joueur)
{
NkBitWriter writer(buffer, capacite);

writer.WriteU8(joueur.vivant ? 1 : 0);
writer.WriteU8(joueur.numero);
writer.WriteF32(joueur.x);
writer.WriteF32(joueur.y);
writer.WriteF32(joueur.angle);
writer.WriteI32(joueur.sante);

return writer.BytesWritten();

}

// Sérialise l'état du joueur avec les types quantifiés.
uint32 EcrireQuantifie(uint8* buffer, uint32 capacite,
const EtatJoueur& joueur)
{
NkBitWriter writer(buffer, capacite);


writer.WriteBool(joueur.vivant);
writer.WriteU8(joueur.numero);
writer.WriteF32Q(joueur.x, -500.0f, 500.0f, 0.01f);
writer.WriteF32Q(joueur.y, -500.0f, 500.0f, 0.01f);
writer.WriteF32Q(joueur.angle, 0.0f, 360.0f, 0.5f);
writer.WriteInt(joueur.sante, 0, 100);

return writer.BytesWritten();

}

// Lit un paquet contenant les types complets.
EtatJoueur LireComplet(const uint8* buffer, uint32 taille)
{
NkBitReader reader(buffer, taille);
EtatJoueur joueur;

joueur.vivant = reader.ReadU8() != 0;
joueur.numero = reader.ReadU8();
joueur.x = reader.ReadF32();
joueur.y = reader.ReadF32();
joueur.angle = reader.ReadF32();
joueur.sante = reader.ReadI32();

if (reader.IsOverflowed())
{
    std::cerr << "Erreur : lecture du paquet complet impossible.\n";
}

return joueur;
}

// Lit un paquet contenant les données quantifiées.
EtatJoueur LireQuantifie(const uint8* buffer, uint32 taille)
{
NkBitReader reader(buffer, taille);
EtatJoueur joueur;
joueur.vivant = reader.ReadBool();
joueur.numero = reader.ReadU8();
joueur.x = reader.ReadF32Q(-500.0f, 500.0f, 0.01f);
joueur.y = reader.ReadF32Q(-500.0f, 500.0f, 0.01f);
joueur.angle = reader.ReadF32Q(0.0f, 360.0f, 0.5f);
joueur.sante = reader.ReadInt(0, 100);

if (reader.IsOverflowed())
{
    std::cerr << "Erreur : lecture du paquet quantifié impossible.\n";
}

return joueur;

}

// Affiche les différences entre l'état initial et l'état reçu.
void AfficherEcarts(const EtatJoueur& original,
const EtatJoueur& recu)
{
std::cout << std::fixed << std::setprecision(5);
std::cout << "Vivant : "
          << (original.vivant == recu.vivant ? "identique" : "différent")
          << '\n';

std::cout << "Numéro : "
          << std::abs(static_cast<int>(original.numero)
                    - static_cast<int>(recu.numero))
          << '\n';

std::cout << "Position X : "
          << std::abs(original.x - recu.x) << '\n';

std::cout << "Position Y : "
          << std::abs(original.y - recu.y) << '\n';

std::cout << "Angle : "
          << std::abs(original.angle - recu.angle) << '\n';

std::cout << "Santé : "
          << std::abs(original.sante - recu.sante) << '\n';

}

// Écrit dans tailles.txt les tailles et les écarts mesurés.
bool EcrireResultats(const EtatJoueur& original,
const EtatJoueur& complet,
const EtatJoueur& quantifie,
uint32 tailleComplete,
uint32 tailleQuantifiee)
{
std::ofstream fichier("tailles.txt");


if (!fichier.is_open())
{
    std::cerr << "Impossible de créer tailles.txt.\n";
    return false;
}

fichier << std::fixed << std::setprecision(5);

// Tailles mesurées à la réception.
fichier << "Types complets : " << tailleComplete << '\n';
fichier << "Quantifié : " << tailleQuantifiee << '\n';

fichier << "\nÉcart maximal :\n";

// Écarts du paquet utilisant les types complets.
fichier << "Types complets :\n";
fichier << "Vivant : "
        << (original.vivant != complet.vivant ? 1 : 0) << '\n';
fichier << "Numéro : "
        << std::abs(static_cast<int>(original.numero)
                  - static_cast<int>(complet.numero)) << '\n';
fichier << "Position X : "
        << std::abs(original.x - complet.x) << '\n';
fichier << "Position Y : "
        << std::abs(original.y - complet.y) << '\n';
fichier << "Angle : "
        << std::abs(original.angle - complet.angle) << '\n';
fichier << "Santé : "
        << std::abs(original.sante - complet.sante) << '\n';

// Écarts du paquet utilisant la quantification.
fichier << "\nDonnées quantifiées :\n";
fichier << "Vivant : "
        << (original.vivant != quantifie.vivant ? 1 : 0) << '\n';
fichier << "Numéro : "
        << std::abs(static_cast<int>(original.numero)
                  - static_cast<int>(quantifie.numero)) << '\n';
fichier << "Position X : "
        << std::abs(original.x - quantifie.x) << '\n';
fichier << "Position Y : "
        << std::abs(original.y - quantifie.y) << '\n';
fichier << "Angle : "
        << std::abs(original.angle - quantifie.angle) << '\n';
fichier << "Santé : "
        << std::abs(original.sante - quantifie.sante) << '\n';

fichier << "\nCe que le joueur verrait :\n";

// Indique si les différences sont perceptibles.
const float32 ecartX = std::abs(original.x - quantifie.x);
const float32 ecartY = std::abs(original.y - quantifie.y);
const float32 ecartAngle = std::abs(original.angle - quantifie.angle);

if (ecartX < 0.01f && ecartY < 0.01f && ecartAngle < 0.5f)
{
    fichier << "Les differences de position et d'angle sont tres faibles. "
            << "Elles devraient etre difficilement perceptibles en jeu.\n";
}
else
{
    fichier << "Les valeurs quantifiees peuvent introduire de petites "
            << "differences de position ou d'angle.\n";
}

fichier << "La quantification reduit la taille du message au prix "
        << "d'une precision moindre.\n";

return true;

}

// Initialise le réseau et vérifie le résultat.
bool InitialiserReseau()
{
if (NkSocket::PlatformInit() != NkNetResult::NK_NET_OK)
{
std::cerr << "Erreur d'initialisation du réseau.\n";
return false;
}

return true;

}

// Mode serveur : reçoit les deux paquets et mesure leurs écarts.
int Serveur()
{
if (!InitialiserReseau())
{
return 1;
}


NkSocket serveur;

if (serveur.Create(NkAddress::Any(PORT),
                   NkSocket::Type::NK_UDP) != NkNetResult::NK_NET_OK)
{
    std::cerr << "Impossible de créer le serveur UDP.\n";
    NkSocket::PlatformShutdown();
    return 1;
}

std::cout << "Serveur en attente sur le port "
          << PORT << "...\n";

uint8 buffer[256]{};

EtatJoueur joueurComplet;
EtatJoueur joueurQuantifie;

uint32 tailleComplete = 0;
uint32 tailleQuantifiee = 0;

// Le serveur reçoit d'abord le paquet complet, puis le quantifié.
for (int paquet = 0; paquet < 2; ++paquet)
{
    uint32 tailleRecue = 0;
    NkAddress expediteur;

    NkNetResult resultat = serveur.RecvFrom(
        buffer, sizeof(buffer), tailleRecue, expediteur);

    if (resultat != NkNetResult::NK_NET_OK || tailleRecue == 0)
    {
        std::cerr << "Erreur de réception du paquet.\n";
        serveur.Close();
        NkSocket::PlatformShutdown();
        return 1;
    }

    std::cout << "\nPaquet reçu : "
              << tailleRecue << " octets\n";

    if (paquet == 0)
    {
        tailleComplete = tailleRecue;
        joueurComplet = LireComplet(buffer, tailleRecue);

        std::cout << "Décodage des types complets :\n";
        AfficherEcarts(EtatJoueur{}, joueurComplet);
    }
    else
    {
        tailleQuantifiee = tailleRecue;
        joueurQuantifie = LireQuantifie(buffer, tailleRecue);

        std::cout << "Décodage des données quantifiées :\n";
        AfficherEcarts(EtatJoueur{}, joueurQuantifie);
    }
}

// Compare les données reçues aux valeurs d'origine du programme.
EtatJoueur original;

if (!EcrireResultats(original, joueurComplet, joueurQuantifie,
                     tailleComplete, tailleQuantifiee))
{
    serveur.Close();
    NkSocket::PlatformShutdown();
    return 1;
}

std::cout << "\nRésultats écrits dans tailles.txt.\n";

serveur.Close();
NkSocket::PlatformShutdown();

return 0;


}

// Mode client : sérialise et envoie les deux paquets.
int Client()
{
if (!InitialiserReseau())
{
return 1;
}

NkSocket client;

if (client.Create(NkAddress::Any(0),
                  NkSocket::Type::NK_UDP) != NkNetResult::NK_NET_OK)
{
    std::cerr << "Impossible de créer le client UDP.\n";
    NkSocket::PlatformShutdown();
    return 1;
}

EtatJoueur joueur;

uint8 paquetComplet[256]{};
uint8 paquetQuantifie[256]{};

// Sérialiser une seule fois chaque paquet.
NkBitWriter writerComplet(paquetComplet, sizeof(paquetComplet));

writerComplet.WriteU8(joueur.vivant ? 1 : 0);
writerComplet.WriteU8(joueur.numero);
writerComplet.WriteF32(joueur.x);
writerComplet.WriteF32(joueur.y);
writerComplet.WriteF32(joueur.angle);
writerComplet.WriteI32(joueur.sante);

NkBitWriter writerQuantifie(paquetQuantifie, sizeof(paquetQuantifie));

writerQuantifie.WriteBool(joueur.vivant);
writerQuantifie.WriteU8(joueur.numero);
writerQuantifie.WriteF32Q(joueur.x, -500.0f, 500.0f, 0.01f);
writerQuantifie.WriteF32Q(joueur.y, -500.0f, 500.0f, 0.01f);
writerQuantifie.WriteF32Q(joueur.angle, 0.0f, 360.0f, 0.5f);
writerQuantifie.WriteInt(joueur.sante, 0, 100);

// Vérifier que les écritures se sont bien déroulées.
if (writerComplet.IsOverflowed() || writerQuantifie.IsOverflowed())
{
    std::cerr << "Erreur : buffer d'écriture trop petit.\n";
    client.Close();
    NkSocket::PlatformShutdown();
    return 1;
}

// Conserver les tailles avant tout nouvel accès aux writers.
const uint32 tailleComplete = writerComplet.BytesWritten();
const uint32 tailleQuantifiee = writerQuantifie.BytesWritten();

const uint32 bitsComplets = writerComplet.BitsWritten();
const uint32 bitsQuantifies = writerQuantifie.BitsWritten();

std::cout << "Types complets : "
          << tailleComplete << " octets, "
          << bitsComplets << " bits\n";

std::cout << "Quantifié : "
          << tailleQuantifiee << " octets, "
          << bitsQuantifies << " bits\n";

// Envoyer les données effectivement écrites dans les buffers.
NkAddress destination = NkAddress::Loopback(PORT);

if (client.SendTo(paquetComplet, tailleComplete,
                  destination) != NkNetResult::NK_NET_OK)
{
    std::cerr << "Erreur d'envoi du paquet complet.\n";
    client.Close();
    NkSocket::PlatformShutdown();
    return 1;
}

if (client.SendTo(paquetQuantifie, tailleQuantifiee,
                  destination) != NkNetResult::NK_NET_OK)
{
    std::cerr << "Erreur d'envoi du paquet quantifié.\n";
    client.Close();
    NkSocket::PlatformShutdown();
    return 1;
}

std::cout << "Les deux paquets ont été envoyés.\n";

client.Close();
NkSocket::PlatformShutdown();

return 0;

}


int main(int argc, char* argv[])
{
// Sélectionner le mode avec l'argument "serveur" ou "client".
if (argc >= 2 && std::strcmp(argv[1], "serveur") == 0)
{
return Serveur();
}

if (argc >= 2 && std::strcmp(argv[1], "client") == 0)
{
    return Client();
}

std::cout << "Utilisation :\n";
std::cout << "  octets.exe serveur\n";
std::cout << "  octets.exe client\n";

return 0;

}
