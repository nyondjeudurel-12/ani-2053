#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

// Cette structure garde les informations de chaque caractere.
struct Glyphe
{
    int avance;
    int x0;
    int y0;
    int x1;
    int y1;
};

int main()
{
    int G;

    // On lit le nombre de caracteres disponibles dans la table.
    if (!(cin >> G))
    {
        return 0;
    }

    map<char, Glyphe> glyphes;

    // On enregistre les informations de chaque caractere.
    for (int i = 0; i < G; ++i)
    {
        char c;
        Glyphe glyphe;

        cin >> c
            >> glyphe.avance
            >> glyphe.x0
            >> glyphe.y0
            >> glyphe.x1
            >> glyphe.y1;

        glyphes[c] = glyphe;
    }

    int K;

    // On lit le nombre de corrections de crénage.
    cin >> K;

    map<pair<char, char>, int> crenages;

    // On enregistre la correction associee a chaque couple.
    for (int i = 0; i < K; ++i)
    {
        char c1;
        char c2;
        int correction;

        cin >> c1 >> c2 >> correction;

        crenages[{c1, c2}] = correction;
    }

    string texte;
    int ox;
    int oy;

    // On recupere le texte et la position de sa ligne de base.
    cin >> texte >> ox >> oy;

    int x = ox;

    // Ces variables serviront a calculer la boite du texte.
    bool dessinExiste = false;
    int minx = 0;
    int miny = 0;
    int maxx = 0;
    int maxy = 0;

    int absents = 0;

    // On parcourt le texte caractere par caractere.
    for (size_t i = 0; i < texte.size(); ++i)
    {
        char c = texte[i];

        // Si le caractere n'existe pas dans la table, on le signale.
        auto it = glyphes.find(c);

        if (it == glyphes.end())
        {
            cout << c << " ABSENT\n";
            ++absents;
            continue;
        }

        const Glyphe& glyphe = it->second;

        // On affiche la position du curseur pour ce caractere.
        cout << c << ' ' << x << '\n';
        // Un caractere est dessine seulement si son rectangle
        // possede une largeur et une hauteur positives.
        if (glyphe.x1 > glyphe.x0 && glyphe.y1 > glyphe.y0)
        {
            int gx0 = x + glyphe.x0;
            int gy0 = oy + glyphe.y0;
            int gx1 = x + glyphe.x1;
            int gy1 = oy + glyphe.y1;

            // Le premier rectangle dessine initialise la boite.
            if (!dessinExiste)
            {
                minx = gx0;
                miny = gy0;
                maxx = gx1;
                maxy = gy1;
                dessinExiste = true;
            }
            else
            {
                // On agrandit la boite pour contenir le nouveau rectangle.
                minx = min(minx, gx0);
                miny = min(miny, gy0);
                maxx = max(maxx, gx1);
                maxy = max(maxy, gy1);
            }
        }

        // Le curseur avance selon les informations du caractere.
        x += glyphe.avance;

        // On applique le crenage si le caractere suivant existe
        // et si le couple est present dans la table.
        if (i + 1 < texte.size())
        {
            char suivant = texte[i + 1];
            // On ne cherche pas de crenage apres un caractere
            // absent de la table.
            if (glyphes.find(suivant) != glyphes.end())
            {
                auto itCrenage = crenages.find({c, suivant});

                if (itCrenage != crenages.end())
                {
                    x += itCrenage->second;
                }
            }
        }
    }

    // On affiche la position finale du curseur.
    cout << "CURSEUR " << x << '\n';
    // Si aucun rectangle n'a ete dessine, il n'y a pas de boite.
    if (!dessinExiste)
    {
        cout << "BOITE AUCUNE\n";
        cout << "MONTE 0\n";
        cout << "DESCEND 0\n";
        cout << "ECRAN RIEN\n";
    }
    else
    {
        cout << "BOITE "
             << minx << ' '
             << miny << ' '
             << maxx << ' '
             << maxy << '\n';

        // On calcule la distance entre la ligne de base
        // et le point le plus haut du texte.
        int monte = (miny < oy) ? oy - miny : 0;
        // On calcule la distance entre la ligne de base
        // et le point le plus bas du texte.
        int descend = (maxy > oy) ? maxy - oy : 0;

        cout << "MONTE " << monte << '\n';
        cout << "DESCEND " << descend << '\n';
        // On verifie si le texte est entierement au-dessus de l'ecran
        // ou s'il depasse simplement par le haut.
        if (maxy <= 0)
        {
            cout << "ECRAN HORS\n";
        }
        else if (miny < 0)
        {
            cout << "ECRAN COUPE\n";
        }
        else
        {
            cout << "ECRAN VISIBLE\n";
        }
    }
    // On affiche le nombre de caracteres absents de la table.
    cout << "ABSENTS " << absents << '\n';

    return 0;
}