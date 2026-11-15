#include <iostream>
#include <string>

struct Image
{
    // Informations de l'image
    long long id;
    double x;
    double y;
    double echelle;
    double rotation;
    double opacite;
    int miroirX;
    int miroirY;
    long long largeur;
    long long hauteur;
    int selectionne;
    std::string chemin;
    long long octets;
};

int main()
{
    int n;
    std::cin >> n;

    int restent = 0;
    int changes = 0;

    // Lire chaque image dans l'ordre
    for (int i = 1; i <= n; ++i)
    {
        Image image;

        // Lire les treize informations de l'image
        std::cin >> image.id
                 >> image.x
                 >> image.y
                 >> image.echelle
                 >> image.rotation
                 >> image.opacite
                 >> image.miroirX
                 >> image.miroirY
                 >> image.largeur
                 >> image.hauteur
                 >> image.selectionne
                 >> image.chemin
                 >> image.octets;

        // Une image sans octets ne peut pas être rouverte
        if (image.octets == 0)
        {
            std::cout << "ITEM " << i << " SAUTE\n";
            continue;
        }

        // Cette image revient dans la planche
        ++restent;

        std::cout << "ITEM " << i << " " << restent;

        int changementsImage = 0;

        // L'identifiant revient à zéro
        if (image.id != 0)
        {
            std::cout << " id";
            ++changementsImage;
        }

        // La sélection revient à zéro
        if (image.selectionne == 1)
        {
            std::cout << " selected";
            ++changementsImage;
        }

        // Le chemin d'origine revient vide
        if (image.chemin != "-")
        {
            std::cout << " sourcePath";
            ++changementsImage;
        }

        // Afficher AUCUN si aucun champ n'a changé
        if (changementsImage == 0)
        {
            std::cout << " AUCUN";
        }

        std::cout << '\n';

        changes += changementsImage;
    }

    // Afficher le bilan final
    std::cout << "RESTENT " << restent << '\n';
    std::cout << "CHANGES " << changes << '\n';

    return 0;
}