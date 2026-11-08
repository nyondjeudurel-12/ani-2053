#include <iostream>

// Premier concept : contour géométrique d'un glyphe.
namespace nkentseu {
    struct NkShape {
        int nombreAretes = 0;
    };
}

// Deuxième concept : forme destinée au rendu 2D.
namespace nkentseu {
    namespace renderer {
        class NkShape {
        public:
            int nombrePoints = 0;
        };
    }
}

// Activer cette partie pour observer l'ambiguïté à la compilation.
#ifdef DEMONSTRER_AMBIGUITE

using namespace nkentseu;
using namespace nkentseu::renderer;

int main() {
    NkShape forme; // ERREUR : NkShape est ambigu.
    return 0;
}

#else

int main() {
    // Correction : préciser l'espace de noms de chaque type.
    nkentseu::NkShape contourGlyphe;
    nkentseu::renderer::NkShape formeGraphique;

    contourGlyphe.nombreAretes = 4;
    formeGraphique.nombrePoints = 4;

    std::cout << "Contour du glyphe : "
              << contourGlyphe.nombreAretes << " aretes\n";

    std::cout << "Forme graphique : "
              << formeGraphique.nombrePoints << " points\n";

    return 0;
}

#endif