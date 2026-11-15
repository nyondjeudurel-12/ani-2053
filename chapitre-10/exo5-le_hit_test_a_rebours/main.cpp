#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct Image
{
    std::string nom;
    double x;
    double y;
    double largeur;
    double hauteur;
    double echelle;
};

// Vérifie si un point touche le rectangle de l'image.
bool touche(const Image& image, double px, double py)
{
    const double demiLargeur = image.largeur * image.echelle / 2.0;
    const double demiHauteur = image.hauteur * image.echelle / 2.0;

    return std::fabs(px - image.x) <= demiLargeur
        && std::fabs(py - image.y) <= demiHauteur;
}

// Recherche de la dernière image vers la première.
std::string rechercheRebours(
    const std::vector<Image>& images,
    double px,
    double py)
{
    for (int i = static_cast<int>(images.size()) - 1; i >= 0; --i)
    {
        if (touche(images[i], px, py))
        {
            return images[i].nom;
        }
    }

    return "AUCUN";
}

// Recherche de la première image vers la dernière.
std::string rechercheEndroit(
    const std::vector<Image>& images,
    double px,
    double py)
{
    for (const Image& image : images)
    {
        if (touche(image, px, py))
        {
            return image.nom;
        }
    }

    return "AUCUN";
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<Image> images;

    // Lecture des images.
    for (int i = 0; i < n; ++i)
    {
        Image image;

        std::cin >> image.nom
                 >> image.x
                 >> image.y
                 >> image.largeur
                 >> image.hauteur
                 >> image.echelle;

        images.push_back(image);
    }

    int q;
    std::cin >> q;

    int erreurs = 0;

    // Traitement de chaque clic.
    for (int i = 1; i <= q; ++i)
    {
        double px;
        double py;

        std::cin >> px >> py;

        const std::string rebours =
            rechercheRebours(images, px, py);

        const std::string endroit =
            rechercheEndroit(images, px, py);

        std::cout << "CLIC " << i << " "
                  << rebours << " "
                  << endroit << '\n';

        if (rebours != endroit)
        {
            ++erreurs;
        }
    }

    // Affichage du nombre de différences.
    std::cout << "ERREURS " << erreurs << '\n';

    return 0;
}