#include <iostream>
#include "NKMedia/Video/NkVideoReader.h"
#include "NKMedia/NkMediaProbe.h"

using namespace nkentseu::media;

const char* NomTypePiste(NkMediaTrackType type)
{
    switch (type)
    {
        case NkMediaTrackType::NK_VIDEO:
            return "VIDEO";

        case NkMediaTrackType::NK_AUDIO:
            return "AUDIO";

        default:
            return "INCONNU";
    }
}

int main()
{
    const char* fichiers[] =
    {
        "film.mp4",
        "film_coupe.mp4",
        "texte.mp4"
    };

    for (const char* fichier : fichiers)
    {
        std::cout << "\n====================================\n";
        std::cout << "Fichier : " << fichier << '\n';

        // Tester l'ouverture du fichier.
        NkVideoReader lecteur;
        const bool ouvert = lecteur.Open(fichier);

        int images = 0;

        if (ouvert)
        {
            const NkVideoReaderInfo& info = lecteur.Info();

            std::cout << "Ouvert : oui\n";
            std::cout << "Conteneur du lecteur : "
                      << info.container.CStr() << '\n';
            std::cout << "Codec du lecteur : "
                      << info.codec.CStr() << '\n';
            std::cout << "Largeur : " << info.width << '\n';
            std::cout << "Hauteur : " << info.height << '\n';

            NkVideoFrame image;

            while (lecteur.ReadFrame(image))
            {
                ++images;
            }

            std::cout << "Images lues : " << images << '\n';
            lecteur.Close();
        }
        else
        {
            std::cout << "Ouvert : non\n";
            std::cout << "Images lues : 0\n";
        }

        // Examiner le fichier indépendamment du lecteur vidéo.
        NkMediaInfo mediaInfo;
        const bool sondeOK =
            NkMediaProbe::ProbeFile(fichier, mediaInfo);

        if (sondeOK)
        {
            std::cout << "Conteneur de la sonde : "
                      << mediaInfo.ContainerName() << '\n';

            for (nkentseu::nk_size i = 0; i < mediaInfo.tracks.Size(); ++i)
{
    const NkMediaTrack& piste = mediaInfo.tracks[i];

    std::cout << "Piste : " << NomTypePiste(piste.type)
              << ", codec : " << piste.codec.CStr() << '\n';

    if (piste.type == NkMediaTrackType::NK_VIDEO)
    {
        std::cout << "Dimensions de la piste : "
                  << piste.width << " x " << piste.height << '\n';
    }
}
        }
        else
        {
            std::cout << "Conteneur de la sonde : UNKNOWN\n";
            std::cout << "Aucune piste reconnue par la sonde.\n";
        }

        // Résumé à reporter dans resultats.txt.
        std::cout << "file : " << fichier
                  << ", opened : " << (ouvert ? "yes" : "no")
                  << ", frames : " << images
                  << ", probe : "
                  << (sondeOK ? mediaInfo.ContainerName() : "UNKNOWN")
                  << '\n';
    }

    return 0;
}

