#include "C:\Users\nyond\OneDrive\Desktop\PROJETS_GAP\Nkentseu\Applications\NkRef\src\NkRef\NkRefView.h"

#include <iostream>

int main()
{
    // Création d'une vue constante.
    const nkref::NkRefView vue{};

    // Création des coordonnées.
    nkentseu::math::NkVec2f pixel{100.0f, 100.0f};
    nkentseu::math::NkVec2f viewport{800.0f, 600.0f};

    std::cout << "=== TEST DES PROMESSES DE NKREFVIEW ===\n\n";

    // Test de PixelToWorld().
    nkentseu::math::NkVec2f resultat = vue.PixelToWorld(pixel, viewport);

    std::cout << "PixelToWorld() : OK\n";
    std::cout << "Position obtenue : X = " << resultat.x
              << ", Y = " << resultat.y << "\n\n";

    // Test de GridSpacing().
    float espacement = vue.GridSpacing(16.0f);

    std::cout << "GridSpacing() : OK\n";
    std::cout << "Espacement obtenu : " << espacement << "\n\n";

    // Cette méthode modifie la vue : elle doit provoquer une erreur.
    // Décommenter uniquement pour tester l'erreur de compilation.
    // vue.PanByPixels(1.0f, 0.0f);

    std::cout << "Tous les tests valides ont ete executes.\n";

    return 0;
}