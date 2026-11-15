#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>

class Lecteur
{
private:
    const std::vector<std::uint8_t>& donnees;
    std::size_t position = 0;

public:
    explicit Lecteur(const std::vector<std::uint8_t>& octets)
        : donnees(octets)
    {
    }

    // Vérifie qu'il reste suffisamment d'octets.
    bool assez(std::size_t nombre) const
    {
        return position <= donnees.size()
            && nombre <= donnees.size() - position;
    }

    // Lit un octet non signé.
    bool lireU8(std::uint8_t& valeur)
    {
        if (!assez(1))
        {
            return false;
        }

        valeur = donnees[position++];
        return true;
    }

    // Lit un entier de quatre octets en petit-boutiste.
    bool lireU32(std::uint32_t& valeur)
    {
        if (!assez(4))
        {
            return false;
        }

        valeur = 0;

        for (int i = 0; i < 4; ++i)
        {
            valeur |= static_cast<std::uint32_t>(
                donnees[position++]
            ) << (8 * i);
        }

        return true;
    }

    // Lit un nombre flottant IEEE 754 sur quatre octets.
    bool lireF32(float& valeur)
    {
        std::uint32_t bits;

        if (!lireU32(bits))
        {
            return false;
        }

        static_assert(sizeof(float) == sizeof(bits));
        static_assert(std::numeric_limits<float>::is_iec559);

        std::memcpy(&valeur, &bits, sizeof(valeur));
        return true;
    }

    // Ignore un nombre déterminé d'octets.
    bool sauter(std::size_t nombre)
    {
        if (!assez(nombre))
        {
            return false;
        }

        position += nombre;
        return true;
    }
};

struct Image
{
    float x;
    float y;
    float echelle;
    float rotation;
    float opacite;

    std::uint8_t mx;
    std::uint8_t my;

    std::uint32_t largeur;
    std::uint32_t hauteur;
    std::uint32_t taille;
};

struct Point
{
    float x;
    float y;
};

struct Trait
{
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a;

    float epaisseur;

    std::vector<Point> points;
};

// Formate un nombre avec deux décimales.
std::string formater(float valeur)
{
    std::ostringstream flux;

    flux << std::fixed << std::setprecision(2) << valeur;

    std::string resultat = flux.str();

    // Remplace le zéro négatif par un zéro positif.
    if (resultat == "-0.00")
    {
        resultat = "0.00";
    }

    return resultat;
}

int main()
{
    std::size_t nombreOctets;

    if (!(std::cin >> nombreOctets))
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    std::vector<std::uint8_t> donnees;
    donnees.reserve(nombreOctets);

    // Lecture des octets écrits en hexadécimal.
    for (std::size_t i = 0; i < nombreOctets; ++i)
    {
        std::string texte;

        if (!(std::cin >> texte))
        {
            break;
        }

        try
        {
            if (texte.size() != 2)
            {
                break;
            }

            const unsigned long valeur = std::stoul(texte, nullptr, 16);

            if (valeur > 255)
            {
                break;
            }

            donnees.push_back(
                static_cast<std::uint8_t>(valeur)
            );
        }
        catch (...)
        {
            break;
        }
    }

    Lecteur lecteur(donnees);

    // Vérification de la signature NKRF.
    const std::uint8_t signature[4] = {
        0x4E, 0x4B, 0x52, 0x46
    };

    for (int i = 0; i < 4; ++i)
    {
        std::uint8_t octet;

        if (!lecteur.lireU8(octet))
        {
            std::cout << "TRONQUE\n";
            return 0;
        }

        if (octet != signature[i])
        {
            std::cout << "PAS_UNE_PLANCHE\n";
            return 0;
        }
    }

    // Lecture et vérification de la version.
    std::uint32_t version;

    if (!lecteur.lireU32(version))
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    if (version != 1)
    {
        std::cout << "VERSION_INCONNUE "
                  << version << '\n';
        return 0;
    }

    // Lecture des informations de la vue.
    float cx;
    float cy;
    float zoom;

    std::uint8_t theme;
    std::uint8_t grille;
    std::uint8_t remplissage1;
    std::uint8_t remplissage2;

    if (!lecteur.lireF32(cx)
        || !lecteur.lireF32(cy)
        || !lecteur.lireF32(zoom)
        || !lecteur.lireU8(theme)
        || !lecteur.lireU8(grille)
        || !lecteur.lireU8(remplissage1)
        || !lecteur.lireU8(remplissage2))
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    // Lecture du nombre d'images.
    std::uint32_t nombreImages;

    if (!lecteur.lireU32(nombreImages))
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    std::vector<Image> images;

    // Lecture des informations de chaque image.
    for (std::uint32_t i = 0; i < nombreImages; ++i)
    {
        Image image;

        std::uint8_t miroirX;
        std::uint8_t miroirY;
        std::uint8_t ignore1;
        std::uint8_t ignore2;

        if (!lecteur.lireF32(image.x)
            || !lecteur.lireF32(image.y)
            || !lecteur.lireF32(image.echelle)
            || !lecteur.lireF32(image.rotation)
            || !lecteur.lireF32(image.opacite)
            || !lecteur.lireU8(miroirX)
            || !lecteur.lireU8(miroirY)
            || !lecteur.lireU8(ignore1)
            || !lecteur.lireU8(ignore2)
            || !lecteur.lireU32(image.largeur)
            || !lecteur.lireU32(image.hauteur)
            || !lecteur.lireU32(image.taille))
        {
            std::cout << "TRONQUE\n";
            return 0;
        }

        // Convertit les valeurs des miroirs en 0 ou 1.
        image.mx = miroirX != 0 ? 1 : 0;
        image.my = miroirY != 0 ? 1 : 0;

        // Saute les octets correspondant à la source de l'image.
        if (!lecteur.sauter(image.taille))
        {
            std::cout << "TRONQUE\n";
            return 0;
        }

        images.push_back(image);
    }

    // Lecture du nombre de traits.
    std::uint32_t nombreTraits;

    if (!lecteur.lireU32(nombreTraits))
    {
        std::cout << "TRONQUE\n";
        return 0;
    }

    std::vector<Trait> traits;

    // Lecture des traits et de leurs points.
    for (std::uint32_t i = 0; i < nombreTraits; ++i)
    {
        Trait trait;
        std::uint32_t nombrePoints;

        if (!lecteur.lireU8(trait.r)
            || !lecteur.lireU8(trait.g)
            || !lecteur.lireU8(trait.b)
            || !lecteur.lireU8(trait.a)
            || !lecteur.lireF32(trait.epaisseur)
            || !lecteur.lireU32(nombrePoints))
        {
            std::cout << "TRONQUE\n";
            return 0;
        }

        for (std::uint32_t j = 0; j < nombrePoints; ++j)
        {
            Point point;

            if (!lecteur.lireF32(point.x)
                || !lecteur.lireF32(point.y))
            {
                std::cout << "TRONQUE\n";
                return 0;
            }

            trait.points.push_back(point);
        }

        traits.push_back(trait);
    }

    // Affichage de la vue.
    std::cout << "VUE "
              << formater(cx) << " "
              << formater(cy) << " "
              << formater(zoom) << '\n';

    // Affichage du thème.
    std::cout << "THEME "
              << (theme != 0 ? "SOMBRE" : "CLAIR")
              << '\n';

    // Affichage de l'état de la grille.
    std::cout << "GRILLE "
              << (grille == 0 ? "AFFICHEE" : "CACHEE")
              << '\n';

    // Affichage des images.
    std::cout << "IMAGES " << images.size() << '\n';

    for (std::size_t i = 0; i < images.size(); ++i)
    {
        const Image& image = images[i];

        std::cout << "IMAGE " << i + 1 << " "
                  << formater(image.x) << " "
                  << formater(image.y) << " "
                  << formater(image.echelle) << " "
                  << formater(image.rotation) << " "
                  << formater(image.opacite) << " "
                  << static_cast<int>(image.mx) << " "
                  << static_cast<int>(image.my) << " "
                  << image.largeur << " "
                  << image.hauteur << " "
                  << image.taille << '\n';
    }

    // Affichage des traits.
    std::cout << "TRAITS " << traits.size() << '\n';

    for (std::size_t i = 0; i < traits.size(); ++i)
    {
        const Trait& trait = traits[i];

        std::cout << "TRAIT " << i + 1 << " "
                  << static_cast<int>(trait.r) << " "
                  << static_cast<int>(trait.g) << " "
                  << static_cast<int>(trait.b) << " "
                  << static_cast<int>(trait.a) << " "
                  << formater(trait.epaisseur) << " "
                  << trait.points.size() << '\n';

        // Affichage des points du trait.
        for (const Point& point : trait.points)
        {
            std::cout << "POINT "
                      << formater(point.x) << " "
                      << formater(point.y) << '\n';
        }
    }

    return 0;
}