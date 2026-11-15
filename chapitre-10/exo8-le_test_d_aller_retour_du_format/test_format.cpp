#include <iostream>
#include "NkRef/NkRefFile.h"

int main() {
    using namespace nkref;
    using nkentseu::uint8;

    // =====================================================
    // 1. Création d'une première planche avec deux images
    // =====================================================

    NkRefBoard board;

    // Première image
    NkRefItem image1;
    image1.id = 1;
    image1.pos = {100.0f, 50.0f};
    image1.scale = 1.5f;
    image1.rotationDeg = 15.0f;
    image1.opacity = 1.0f;
    image1.texW = 256;
    image1.texH = 128;
    board.items.PushBack(image1);

    // Deuxième image
    NkRefItem image2;
    image2.id = 2;
    image2.pos = {-80.0f, 120.0f};
    image2.scale = 0.8f;
    image2.rotationDeg = 30.0f;
    image2.opacity = 0.75f;
    image2.texW = 512;
    image2.texH = 256;
    board.items.PushBack(image2);

    // =====================================================
    // 2. Ajout d'un trait de crayon
    // =====================================================

    NkRefStroke stroke;
    stroke.r = 255;
    stroke.g = 100;
    stroke.b = 40;
    stroke.a = 255;
    stroke.widthWorld = 3.5f;

    // Points du trait
    stroke.points.PushBack({10.0f, 20.0f});
    stroke.points.PushBack({30.0f, 40.0f});
    stroke.points.PushBack({50.0f, 25.0f});

    board.strokes.PushBack(stroke);

    // =====================================================
    // 3. Création d'une vue déplacée
    // =====================================================

    NkRefView view;
    view.center = {120.0f, 75.0f};
    view.zoom = 2.5f;

    bool darkTheme = true;
    bool showGrid = false;

    // =====================================================
    // 4. Création des octets sources des deux images
    // =====================================================

    const uint8 image1Data[] = {
        10, 20, 30, 40, 50, 60, 70, 80
    };

    const uint8 image2Data[] = {
        100, 110, 120, 130, 140, 150
    };

    NkRefFileImage images[2];

    images[0].data = image1Data;
    images[0].size = sizeof(image1Data);

    images[1].data = image2Data;
    images[1].size = sizeof(image2Data);

    // =====================================================
    // 5. Première sérialisation
    // =====================================================

    nkentseu::NkVector<uint8> premierFichier;

    NkRefSerialize(
        premierFichier,
        board,
        images,
        view,
        darkTheme,
        showGrid
    );

    // =====================================================
    // 6. Désérialisation du premier fichier
    // =====================================================

    nkentseu::NkVector<NkRefLoadedItem> loadedItems;
    nkentseu::NkVector<NkRefStroke> loadedStrokes;

    NkRefView loadedView;
    bool loadedDark = false;
    bool loadedShowGrid = true;

    const bool lectureReussie = NkRefDeserialize(
        premierFichier.Data(),
        premierFichier.Size(),
        loadedItems,
        loadedStrokes,
        loadedView,
        loadedDark,
        loadedShowGrid
    );

    // =====================================================
    // 7. Reconstruction de la deuxième planche
    // =====================================================

    NkRefBoard restoredBoard;

    NkRefFileImage restoredImages[2];

    if (lectureReussie && loadedItems.Size() == 2) {

        // Récupération des images et de leurs octets sources
        for (nkentseu::usize i = 0; i < loadedItems.Size(); ++i) {
            restoredBoard.items.PushBack(loadedItems[i].item);

            restoredImages[i].data = loadedItems[i].src.Data();
            restoredImages[i].size = loadedItems[i].src.Size();
        }

        // Récupération des traits
        for (nkentseu::usize i = 0; i < loadedStrokes.Size(); ++i) {
            restoredBoard.strokes.PushBack(loadedStrokes[i]);
        }
    }

    // =====================================================
    // 8. Deuxième sérialisation
    // =====================================================

    nkentseu::NkVector<uint8> deuxiemeFichier;

    if (lectureReussie && loadedItems.Size() == 2) {
        NkRefSerialize(
            deuxiemeFichier,
            restoredBoard,
            restoredImages,
            loadedView,
            loadedDark,
            loadedShowGrid
        );
    }

    // =====================================================
    // 9. Comparaison octet par octet
    // =====================================================

    bool identiques = lectureReussie &&
                      premierFichier.Size() == deuxiemeFichier.Size();

    if (identiques) {
        for (nkentseu::usize i = 0; i < premierFichier.Size(); ++i) {
            if (premierFichier[i] != deuxiemeFichier[i]) {
                identiques = false;
                break;
            }
        }
    }

    // =====================================================
    // 10. Affichage du résultat
    // =====================================================

    std::cout
        << "octets : " << premierFichier.Size()
        << ", relu : " << (lectureReussie ? "OUI" : "NON")
        << ", identiques : " << (identiques ? "OUI" : "NON")
        << std::endl;

    return identiques ? 0 : 1;
}