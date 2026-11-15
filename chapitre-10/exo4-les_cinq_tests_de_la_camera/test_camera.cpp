#include <cmath>
#include <iostream>

#include "NkRef/NkRefView.h"

using nkref::NkRefView;
using nkentseu::math::NkVec2f;

// Tolérance pour comparer les nombres à virgule.
bool PresqueEgal(float a, float b)
{
    return std::fabs(a - b) <= 0.001f;
}

// Test 1 : pixel -> monde -> pixel doit retrouver le pixel initial.
bool aller_retour()
{
    NkRefView camera;

    const NkVec2f viewport{800.0f, 600.0f};
    const NkVec2f pixel{123.0f, 245.0f};

    const NkVec2f monde = camera.PixelToWorld(pixel, viewport);
    const NkVec2f resultat = camera.WorldToPixel(monde, viewport);

    return PresqueEgal(resultat.x, pixel.x)
        && PresqueEgal(resultat.y, pixel.y);
}

// Test 2 : le point du monde sous le curseur reste fixe pendant le zoom.
bool point_fixe()
{
    NkRefView camera;

    const NkVec2f viewport{800.0f, 600.0f};
    const NkVec2f pixel{123.0f, 87.0f};

    const NkVec2f avant = camera.PixelToWorld(pixel, viewport);

    camera.ZoomAtPixel(2.0f, pixel, viewport);

    const NkVec2f apres = camera.PixelToWorld(pixel, viewport);

    return PresqueEgal(avant.x, apres.x)
        && PresqueEgal(avant.y, apres.y);
}

// Test 3 : le zoom doit respecter ses limites minimale et maximale.
bool bornes()
{
    NkRefView camera;

    const NkVec2f viewport{800.0f, 600.0f};
    const NkVec2f pixel{400.0f, 300.0f};

    camera.ZoomAtPixel(1000.0f, pixel, viewport);

    const bool maximumRespecte =
        camera.zoom <= NkRefView::kZoomMax
        && camera.zoom >= NkRefView::kZoomMin;

    camera.ZoomAtPixel(0.00001f, pixel, viewport);

    const bool minimumRespecte =
        camera.zoom >= NkRefView::kZoomMin
        && camera.zoom <= NkRefView::kZoomMax;

    return maximumRespecte && minimumRespecte;
}

// Test 4 : l'espacement de la grille ne diminue pas quand on dézoome.
bool grille()
{
    NkRefView camera;

    const NkVec2f viewport{800.0f, 600.0f};
    const NkVec2f centre{400.0f, 300.0f};

    const float avant = camera.GridSpacing(32.0f);

    camera.ZoomAtPixel(0.5f, centre, viewport);

    const float apres = camera.GridSpacing(32.0f);

    return apres >= avant;
}

// Test 5 : Reset doit remettre le centre et le zoom à leur valeur initiale.
bool origine()
{
    NkRefView camera;

    const NkVec2f viewport{800.0f, 600.0f};
    const NkVec2f pixel{200.0f, 150.0f};

    camera.ZoomAtPixel(2.0f, pixel, viewport);
    camera.PanByPixels(100.0f, 50.0f);

    camera.Reset();

    return PresqueEgal(camera.center.x, 0.0f)
        && PresqueEgal(camera.center.y, 0.0f)
        && PresqueEgal(camera.zoom, 1.0f);
}

int main()
{
    // Exécuter les cinq tests et afficher leur résultat.
    std::cout << "TEST aller_retour : "
              << (aller_retour() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST point_fixe : "
              << (point_fixe() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST bornes : "
              << (bornes() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST grille : "
              << (grille() ? "OK" : "ECHEC") << '\n';

    std::cout << "TEST origine : "
              << (origine() ? "OK" : "ECHEC") << '\n';

    return 0;
}