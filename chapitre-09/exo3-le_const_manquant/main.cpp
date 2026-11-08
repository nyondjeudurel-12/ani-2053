#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Methode
{
    std::string nom;
    bool declareeConst = false;
    bool modifie = false;

    std::vector<std::string> nomsAppeles;
    std::vector<int> appels;

    bool pourraitEtreConst = false;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<Methode> methodes(n);
    std::unordered_map<std::string, int> indices;

    // Étape 1 : lire toutes les méthodes.
    for (int i = 0; i < n; ++i)
    {
        std::string declaration;
        int modifie;
        int k;

        std::cin >> methodes[i].nom >> declaration >> modifie >> k;

        methodes[i].declareeConst = (declaration == "const");
        methodes[i].modifie = (modifie == 1);

        indices[methodes[i].nom] = i;

        for (int j = 0; j < k; ++j)
        {
            std::string nomAppel;
            std::cin >> nomAppel;

            methodes[i].nomsAppeles.push_back(nomAppel);
        }
    }

    // Étape 2 : convertir les noms des appels en indices.
    for (int i = 0; i < n; ++i)
    {
        for (const std::string& nom : methodes[i].nomsAppeles)
        {
            methodes[i].appels.push_back(indices.at(nom));
        }
    }

    // Étape 3 : identifier les méthodes candidates.
    for (int i = 0; i < n; ++i)
    {
        methodes[i].pourraitEtreConst =
            !methodes[i].declareeConst && !methodes[i].modifie;
    }

    // Étape 4 : éliminer les méthodes qui appellent
    // une méthode impossible à rendre const.
    bool changement = true;

    while (changement)
    {
        changement = false;

        for (int i = 0; i < n; ++i)
        {
            if (!methodes[i].pourraitEtreConst)
                continue;

            for (int appel : methodes[i].appels)
            {
                if (!methodes[appel].declareeConst &&
                    !methodes[appel].pourraitEtreConst)
                {
                    methodes[i].pourraitEtreConst = false;
                    changement = true;
                    break;
                }
            }
        }
    }

    // Étape 5 : préparer les listes de résultats.
    std::vector<std::string> pourrait;
    std::vector<std::string> racines;

    for (int i = 0; i < n; ++i)
    {
        if (!methodes[i].pourraitEtreConst)
            continue;

        pourrait.push_back(methodes[i].nom);

        // Une racine appelle uniquement des méthodes
        // déjà déclarées const.
        bool estRacine = true;

        for (int appel : methodes[i].appels)
        {
            if (!methodes[appel].declareeConst)
            {
                estRacine = false;
                break;
            }
        }

        if (estRacine)
            racines.push_back(methodes[i].nom);
    }

    // Étape 6 : calculer les passes simultanées.
    std::vector<bool> estConst(n, false);
    std::vector<bool> enAttente(n, false);

    for (int i = 0; i < n; ++i)
    {
        estConst[i] = methodes[i].declareeConst;
        enAttente[i] = methodes[i].pourraitEtreConst;
    }

    int passes = 0;

    while (true)
    {
        std::vector<int> aDeclarer;

        // On recherche toutes les méthodes prêtes
        // avant de modifier leur état.
        for (int i = 0; i < n; ++i)
        {
            if (!enAttente[i])
                continue;

            bool prete = true;

            for (int appel : methodes[i].appels)
            {
                if (!estConst[appel])
                {
                    prete = false;
                    break;
                }
            }

            if (prete)
                aDeclarer.push_back(i);
        }

        // Si aucune méthode ne peut avancer, on arrête.
        if (aDeclarer.empty())
            break;

        // Toutes les méthodes prêtes sont déclarées const
        // en même temps : elles appartiennent à la même passe.
        for (int i : aDeclarer)
        {
            estConst[i] = true;
            enAttente[i] = false;
        }

        ++passes;
    }

    // Étape 7 : afficher exactement le format demandé.
    std::cout << "POURRAIT";

    if (pourrait.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (const std::string& nom : pourrait)
            std::cout << " " << nom;
    }

    std::cout << '\n';

    std::cout << "RACINES";

    if (racines.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (const std::string& nom : racines)
            std::cout << " " << nom;
    }

    std::cout << '\n';

    std::cout << "PASSES " << passes << '\n';

    return 0;
}