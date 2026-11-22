#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Représente une entrée de la matrice.
struct Entree
{
    string nom;
    int valeur;
    int cout;
    string etiquette;
    string genre;
    string cible;

    int ordre;
    int numeroCase;
};

// Donne la priorité de chaque étiquette.
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

// Détermine la case selon la valeur et le coût.
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
    int nombreEntrees;
    cin >> nombreEntrees;

    vector<Entree> entrees;
    vector<Entree> horsListe;

    // Associe chaque nom à sa position dans la liste.
    map<string, int> positions;

    // Lit toutes les entrées.
    for (int i = 0; i < nombreEntrees; ++i)
    {
        Entree entree;

        cin >> entree.nom
            >> entree.valeur
            >> entree.cout
            >> entree.etiquette
            >> entree.genre;

        entree.cible = "";
        entree.ordre = i;

        // Une entrée SOCLE possède un mot supplémentaire.
        if (entree.genre == "SOCLE")
        {
            cin >> entree.cible;
        }

        // Écarte les réécritures, les choix et les entrées sans étiquette.
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

    // Ajuste la valeur des SOCLES selon leur cible.
    for (Entree& entree : entrees)
    {
        if (entree.genre != "SOCLE")
        {
            continue;
        }

        auto position = positions.find(entree.cible);

        // La cible doit être une entrée MANQUE gardée.
        if (position != positions.end())
        {
            const Entree& cible = entrees[position->second];

            if (cible.genre == "MANQUE")
            {
                entree.valeur = max(entree.valeur, cible.valeur);
            }
        }
    }

    // Détermine la case de chaque entrée gardée.
    for (Entree& entree : entrees)
    {
        entree.numeroCase = determinerCase(entree.valeur, entree.cout);
    }

    // Trie les entrées selon les règles de l'énoncé.
    sort(entrees.begin(), entrees.end(),
         [](const Entree& a, const Entree& b)
         {
             if (a.numeroCase != b.numeroCase)
             {
                 return a.numeroCase < b.numeroCase;
             }

             int prioriteA = prioriteEtiquette(a.etiquette);
             int prioriteB = prioriteEtiquette(b.etiquette);

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

    // Affiche les entrées gardées dans leur ordre de classement.
    bool listeHonnete = false;

    const string nomsCases[] =
    {
        "MAINTENANT",
        "DECOUPER",
        "EN_PASSANT",
        "ON_NE_LE_FAIT_PAS"
    };

    for (const Entree& entree : entrees)
    {
        cout << nomsCases[entree.numeroCase]
             << " " << entree.nom
             << " " << entree.etiquette
             << '\n';

        if (entree.numeroCase == 3)
        {
            listeHonnete = true;
        }
    }

    // Affiche les entrées écartées dans leur ordre d'origine.
    for (const Entree& entree : horsListe)
    {
        cout << "HORS_LISTE "
             << entree.nom
             << " " << entree.etiquette
             << '\n';
    }

    // Affiche le verdict final.
    cout << "VERDICT "
         << (listeHonnete ? "HONNETE" : "COMPLAISANT")
         << '\n';

    return 0;
}