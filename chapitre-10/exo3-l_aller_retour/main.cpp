#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

// Représente la caméra du canevas.
struct Camera
{
    double cx = 0.0;
    double cy = 0.0;
    double zoom = 1.0;

    // Convertit un pixel en coordonnées du monde.
    std::pair<double, double> PixelToWorld(
        double px, double py, double width, double height) const
    {
        double x = cx + (px - width / 2.0) / zoom;
        double y = cy + (py - height / 2.0) / zoom;

        return {x, y};
    }

    // Convertit les coordonnées du monde en pixels.
    std::pair<double, double> WorldToPixel(
        double mx, double my, double width, double height) const
    {
        double x = (mx - cx) * zoom + width / 2.0;
        double y = (my - cy) * zoom + height / 2.0;

        return {x, y};
    }

    // Déplace la planche en tenant compte du zoom.
    void PanByPixels(double dx, double dy)
    {
        cx -= dx / zoom;
        cy -= dy / zoom;
    }

    // Zoome en gardant fixe le point situé sous le curseur.
    void ZoomAtPixel(
        double factor, double px, double py,
        double width, double height)
    {
        // Mémoriser le point du monde avant le zoom.
        auto anchor = PixelToWorld(px, py, width, height);

        // Modifier le zoom et respecter ses limites.
        zoom = std::clamp(zoom * factor, 0.02, 64.0);

        // Recalculer le centre pour garder le point fixe.
        cx = anchor.first - (px - width / 2.0) / zoom;
        cy = anchor.second - (py - height / 2.0) / zoom;
    }

    // Calcule le pas de la grille selon le zoom.
    double GridSpacing(double minimumPixels) const
    {
        double spacing = 1.0;

        while (spacing * zoom < minimumPixels)
        {
            spacing *= 2.0;
        }

        while (spacing * 0.5 * zoom >= minimumPixels)
        {
            spacing *= 0.5;
        }

        return spacing;
    }

    // Remet la caméra à son état initial.
    void Reset()
    {
        cx = 0.0;
        cy = 0.0;
        zoom = 1.0;
    }
};

// Formate un nombre avec le nombre de décimales demandé.
std::string FormatNumber(double value, int precision)
{
    std::ostringstream output;
    output << std::fixed << std::setprecision(precision) << value;

    std::string result = output.str();

    // Éviter d'afficher -0.00 ou -0.000000.
    if (result == "-0." + std::string(precision, '0'))
    {
        result.erase(0, 1);
    }

    return result;
}

int main()
{
    double width;
    double height;

    // Lire les dimensions de la fenêtre.
    if (!(std::cin >> width >> height))
    {
        return 0;
    }

    Camera camera;

    std::string command;

    // Lire les commandes jusqu'à la fin de l'entrée.
    while (std::cin >> command)
    {
        if (command == "VERS_MONDE")
        {
            double px;
            double py;
            std::cin >> px >> py;

            auto point = camera.PixelToWorld(
                px, py, width, height);

            std::cout << "MONDE "
                      << FormatNumber(point.first, 2) << " "
                      << FormatNumber(point.second, 2) << '\n';
        }
        else if (command == "VERS_PIXEL")
        {
            double mx;
            double my;
            std::cin >> mx >> my;

            auto point = camera.WorldToPixel(
                mx, my, width, height);

            std::cout << "PIXEL "
                      << FormatNumber(point.first, 2) << " "
                      << FormatNumber(point.second, 2) << '\n';
        }
        else if (command == "DEPLACE")
        {
            double dx;
            double dy;
            std::cin >> dx >> dy;

            camera.PanByPixels(dx, dy);
        }
        else if (command == "ZOOM")
        {
            double factor;
            double px;
            double py;

            std::cin >> factor >> px >> py;

            camera.ZoomAtPixel(
                factor, px, py, width, height);
        }
        else if (command == "GRILLE")
        {
            double minimumPixels;
            std::cin >> minimumPixels;

            double spacing = camera.GridSpacing(minimumPixels);

            std::cout << "GRILLE "
                      << FormatNumber(spacing, 6) << '\n';
        }
        else if (command == "ORIGINE")
        {
            camera.Reset();
        }
    }

    // Afficher l'état final de la caméra.
    std::cout << "CENTRE "
              << FormatNumber(camera.cx, 2) << " "
              << FormatNumber(camera.cy, 2) << '\n';

    std::cout << "ZOOM "
              << FormatNumber(camera.zoom, 2) << '\n';

    return 0;
}