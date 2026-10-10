
#include <iostream>
#include <filesystem>
#include <string>
#include <thread>
#include <chrono>
#include "NKImage/NKImage.h"
#include "NKLogger/NkLog.h"

// Charge une image et recupere ses informations
void mesurerImage(const char* nom, const char* chemin)
{
    nkentseu::NkImage image;
    // Pause pour simuler un traitement
    std::this_thread::sleep_for(std::chrono::seconds(15)); 
    // On verifie si l'image a bien ete chargee
    if (!image.Load(chemin))
    {
        logger.Error("Chargement echoue : {}", nom);
        return;
    }

    // Recuperation des dimensions de l'image
    int largeur = image.Width();
    int hauteur = image.Height();
    int bytesPP = image.BytesPP();

    // Calcul de la memoire necessaire pour les pixels
    long long tailleCalculee =
        static_cast<long long>(largeur) * hauteur * bytesPP;

    // Taille du fichier sur le disque
    auto tailleFichier = std::filesystem::file_size(chemin);

    // Affichage des resultats dans le journal
    logger.Info("Image : {}", nom);
    logger.Info("Dimensions : {} x {}", largeur, hauteur);
    logger.Info("BytesPP : {}", bytesPP);
    logger.Info("Taille calculee : {} octets", tailleCalculee);
    logger.Info("Taille du fichier : {} octets", tailleFichier);
}

int main()
{
    // Liste des images a tester
    const char* dossier =
        "C:/Users/nyond/OneDrive/Desktop/Espace/Espace/assets/";

    mesurerImage("icone.png", (std::string(dossier) + "icone.png").c_str());
    mesurerImage("dessin.png", (std::string(dossier) + "dessin.png").c_str());
    mesurerImage("capture.png", (std::string(dossier) + "capture.png").c_str());
    mesurerImage("photo1.jpg", (std::string(dossier) + "photo1.jpg").c_str());
    mesurerImage("photo2.jpg", (std::string(dossier) + "photo2.jpg").c_str());

    std::cout << "Mesure des images terminee." << std::endl;

    return 0;
}

