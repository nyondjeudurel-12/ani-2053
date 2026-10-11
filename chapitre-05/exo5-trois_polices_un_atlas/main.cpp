#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Cette structure permet de garder les informations de chaque police
// ainsi que la position du premier et du dernier glyphe.
struct Groupe
{
    string police;
    int n;
    int w;
    int h;
    int xPremier = 0;
    int yPremier = 0;
    int xDernier = 0;
    int yDernier = 0;
};

int main()
{
    int P, L;

    // On lit la marge entre les glyphes et la largeur demandee.
    if (!(cin >> P >> L))
    {
        return 0;
    }

    // On recupere le nombre de groupes de polices.
    int G;
    if (!(cin >> G))
    {
        return 0;
    }

    // S'il n'y a aucun groupe, il n'y a rien a ranger.
    if (G == 0)
    {
        cout << "AUCUN\n";
        return 0;
    }

    vector<Groupe> groupes;
    groupes.reserve(static_cast<size_t>(G));

    int64_t besoin = 0;
    int64_t occupe = 0;

    // On lit les informations de chaque groupe.
    for (int i = 0; i < G; ++i)
    {
        Groupe groupe;

        if (!(cin >> groupe.police
                  >> groupe.n
                  >> groupe.w
                  >> groupe.h))
        {
            return 0;
        }

        groupes.push_back(groupe);

        // On calcule la place necessaire en comptant les marges.
        besoin += static_cast<int64_t>(groupe.n)
                * (groupe.w + P)
                * (groupe.h + P);

        // Ici, on compte seulement la surface des glyphes, sans les marges.
        occupe += static_cast<int64_t>(groupe.n)
                * groupe.w
                * groupe.h;
    }

    int W = L;

    // Si la largeur vaut zero, on la choisit automatiquement.
    if (W == 0)
    {
        W = 512;

        // On augmente la largeur tant que la texture est trop petite.
        while (static_cast<int64_t>(W) * W < 2 * besoin
               && W < 4096)
        {
            W *= 2;
        }
    }

    // Au depart, la texture est carree.
    int H = W;
    int essaisReussis = 0;

    // On essaie de ranger les glyphes au maximum 8 fois.
    for (int essai = 1; essai <= 8; ++essai)
    {
        // Le rangement commence avec le curseur au niveau de la marge.
        int x = P;
        int y = P;

        // e garde la hauteur de l'etagere actuelle.
        int e = 0;
        bool reussi = true;

        // On range les groupes dans l'ordre ou ils ont ete lus.
        for (Groupe& groupe : groupes)
        {
            bool premier = true;

            // Chaque groupe contient plusieurs glyphes de meme taille.
            for (int i = 0; i < groupe.n; ++i)
            {
                int rw = groupe.w + P;
                int rh = groupe.h + P;

                // Si le glyphe ne tient plus sur la ligne,
                // on passe a l'etagere suivante.
                if (x + rw > W - P)
                {
                    x = P;
                    y = y + e + P;
                    e = 0;
                }

                // Si le glyphe ne tient toujours pas, l'essai echoue.
                if (x + rw > W - P || y + rh > H - P)
                {
                    reussi = false;
                    break;
                }

                // On enregistre la position du premier glyphe du groupe.
                if (premier)
                {
                    groupe.xPremier = x;
                    groupe.yPremier = y;
                    premier = false;
                }

                // On garde aussi la position du dernier glyphe.
                groupe.xDernier = x;
                groupe.yDernier = y;

                // On avance pour placer le prochain glyphe.
                x += rw;

                // On garde la plus grande hauteur de l'etagere.
                e = max(e, rh);
            }

            // Inutile de continuer si un glyphe n'a pas pu etre place.
            if (!reussi)
            {
                break;
            }
        }

        // Si tout tient, on conserve le numero de cet essai.
        if (reussi)
        {
            essaisReussis = essai;
            break;
        }

        // Sinon, on agrandit la texture selon la regle demandee.
        if (W == H)
        {
            W *= 2;
        }
        else
        {
            H = W;
        }
    }

    // Si aucun essai n'a fonctionne, on affiche l'echec.
    if (essaisReussis == 0)
    {
        cout << "ESSAIS 8\n";
        cout << "ECHEC\n";
        return 0;
    }

    // On calcule la surface totale de la texture en utilisant
    // un entier sur 64 bits pour eviter un depassement.
    int64_t surfaceTexture = static_cast<int64_t>(W) * H;

    // On calcule le pourcentage de surface non occupee par les glyphes.
    int64_t perdu = (surfaceTexture - occupe) * 100 / surfaceTexture;

    // Affichage du resultat dans le format demande par l'exercice.
    cout << "ESSAIS " << essaisReussis << '\n';
    cout << "TEXTURE " << W << ' ' << H << '\n';

    // Pour chaque groupe, on affiche les coordonnees du premier
    // et du dernier glyphe.
    for (const Groupe& groupe : groupes)
    {
        cout << groupe.police << ' '
             << groupe.xPremier << ' '
             << groupe.yPremier << ' '
             << groupe.xDernier << ' '
             << groupe.yDernier << '\n';
    }

    cout << "OCCUPE " << occupe << '\n';
    cout << "PERDU " << perdu << '\n';

    return 0;
}