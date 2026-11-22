#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Contient les informations d'une ligne de la matrice.
struct Entree
{
    string nom;
    int valeur = 0;
    int cout = 0;
    string etiquette;
    string genre;
    string cible;
    int ordre = 0;
    int numeroCase = 0;
};

// Retourne la priorité d'une étiquette pour le classement.
int prioriteEtiquette(const string& etiquette)
{
    if (etiquette == "MESUREE")
    {
        return 0;
    }

    if (etiquette == "OBSERVEE")
    {
        return 1;
    }

    return 2;
}

// Détermine la case à partir de la valeur et du coût.
int determinerCase(int valeur, int cout)
{
    if (valeur >= 3 && cout < 3)
    {
        return 0; // MAINTENANT
    }

    if (valeur >= 3 && cout >= 3)
    {
        return 1; // DECOUPER
    }

    if (valeur < 3 && cout < 3)
    {
        return 2; // EN_PASSANT
    }

    return 3; // ON_NE_LE_FAIT_PAS
}

int main()
{
    int nombreEntrees = 0;
    if (!(cin >> nombreEntrees))
    {
        return 0;
    }

    vector<Entree> entrees;
    vector<Entree> horsListe;
    map<string, int> positions;

    // Lit les lignes et écarte celles qui ne doivent pas être classées.
    for (int i = 0; i < nombreEntrees; ++i)
    {
        Entree entree;
        entree.ordre = i;

        cin >> entree.nom >> entree.valeur >> entree.cout
            >> entree.etiquette >> entree.genre;

        if (entree.genre == "SOCLE")
        {
            cin >> entree.cible;
        }

        if (entree.genre == "REECRITURE")
        {
            entree.etiquette = "reecriture";
            horsListe.push_back(entree);
        }
        else if (entree.genre == "CHOIX")
        {
            entree.etiquette = "choix";
            horsListe.push_back(entree);
        }
        else if (entree.etiquette == "-")
        {
            entree.etiquette = "sans_etiquette";
            horsListe.push_back(entree);
        }
        else
        {
            positions[entree.nom] = static_cast<int>(entrees.size());
            entrees.push_back(entree);
        }
    }

    // Un SOCLE prend la valeur de sa cible si celle-ci est un MANQUE gardé.
    for (Entree& entree : entrees)
    {
        if (entree.genre != "SOCLE")
        {
            continue;
        }

        const auto position = positions.find(entree.cible);
        if (position != positions.end())
        {
            const Entree& cible = entrees[position->second];
            if (cible.genre == "MANQUE")
            {
                entree.valeur = max(entree.valeur, cible.valeur);
            }
        }
    }

    // Calcule la case de chaque entrée conservée.
    for (Entree& entree : entrees)
    {
        entree.numeroCase = determinerCase(entree.valeur, entree.cout);
    }

    // Trie par case, étiquette, valeur, coût et ordre d'entrée.
    sort(entrees.begin(), entrees.end(),
         [](const Entree& a, const Entree& b)
         {
             if (a.numeroCase != b.numeroCase)
             {
                 return a.numeroCase < b.numeroCase;
             }

             const int prioriteA = prioriteEtiquette(a.etiquette);
             const int prioriteB = prioriteEtiquette(b.etiquette);

             if (prioriteA != prioriteB)
             {
                 return prioriteA < prioriteB;
             }

             if (a.valeur != b.valeur)
             {
                 return a.valeur > b.valeur;
             }

             if (a.cout != b.cout)
             {
                 return a.cout < b.cout;
             }

             return a.ordre < b.ordre;
         });

    bool refus = false;
    const string nomsCases[] = {
        "MAINTENANT",
        "DECOUPER",
        "EN_PASSANT",
        "ON_NE_LE_FAIT_PAS"
    };

    // Affiche les lignes gardées dans l'ordre de la matrice.
    for (const Entree& entree : entrees)
    {
        cout << nomsCases[entree.numeroCase] << " "
             << entree.nom << " " << entree.etiquette << '\n';

        if (entree.numeroCase == 3)
        {
            refus = true;
        }
    }

    // Affiche les lignes écartées dans leur ordre d'origine.
    for (const Entree& entree : horsListe)
    {
        cout << "HORS_LISTE " << entree.nom << " "
             << entree.etiquette << '\n';
    }

    cout << "VERDICT " << (refus ? "HONNETE" : "COMPLAISANT") << '\n';

    return 0;
}
