#include "NkRef/NkRefFile.h"
#include "NKTime/NkChrono.h"
#include <array>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    // Vérifie que le nombre d'images est fourni.
    if (argc != 2)
    {
        std::cerr << "Utilisation : mesure <nombre_images>\n";
        return 1;
    }

    const int nombreImages = std::atoi(argv[1]);

    if (nombreImages <= 0)
    {
        std::cerr << "Le nombre d'images doit être positif.\n";
        return 1;
    }

    // Prépare le tableau et les données communes aux images.
    nkref::NkRefBoard board;

    std::array<nkentseu::uint8, 1000> source{};

    // Remplit les 1000 octets avec des données déterministes.
    for (std::size_t i = 0; i < source.size(); ++i)
    {
        source[i] = static_cast<nkentseu::uint8>((i * 37 + 11) % 256);
    }

    // Chaque image utilise exactement les mêmes données.
    std::vector<nkref::NkRefFileImage> images(
        static_cast<std::size_t>(nombreImages)
    );

    for (int i = 0; i < nombreImages; ++i)
    {
        nkref::NkRefItem item;

        item.id = static_cast<nkentseu::uint32>(i + 1);
        item.pos = {
            static_cast<float>(i * 110),
            static_cast<float>(i * 90)
        };
        item.texW = 100;
        item.texH = 80;

        board.items.PushBack(item);

        images[static_cast<std::size_t>(i)].data = source.data();
        images[static_cast<std::size_t>(i)].size = source.size();
    }

    // Utilise la vue par défaut et prépare le résultat sérialisé.
    nkref::NkRefView view;
    nkentseu::NkVector<nkentseu::uint8> donnees;

    // Mesure les 20 sérialisations.
    nkentseu::NkChrono chronoEcriture;

    for (int i = 0; i < 20; ++i)
    {
        nkref::NkRefSerialize(donnees, board, images.data(), view, false);
    }

    const double tempsEcriture =
        chronoEcriture.Elapsed().ToMilliseconds() / 20.0;

    // Prépare les structures qui recevront les données relues.
    nkentseu::NkVector<nkref::NkRefLoadedItem> imagesRelues;
    nkentseu::NkVector<nkref::NkRefStroke> traitsRelus;

    nkref::NkRefView vueRelue;
    bool themeSombre = false;
    bool afficherGrille = true;

    // Mesure les 20 désérialisations.
    nkentseu::NkChrono chronoLecture;

    for (int i = 0; i < 20; ++i)
    {
        const bool succes = nkref::NkRefDeserialize(
            donnees.Data(),
            donnees.Size(),
            imagesRelues,
            traitsRelus,
            vueRelue,
            themeSombre,
            afficherGrille
        );

        if (!succes)
        {
            std::cerr << "Erreur pendant la deserialisation.\n";
            return 1;
        }
    }

    const double tempsLecture =
        chronoLecture.Elapsed().ToMilliseconds() / 20.0;

    // Affiche les résultats dans un format facile à recopier.
    std::cout << std::fixed << std::setprecision(3)
              << "images : " << nombreImages
              << ", octets : " << donnees.Size()
              << ", ecrire : " << tempsEcriture << " ms"
              << ", relire : " << tempsLecture << " ms\n";

    return 0 ;
    }