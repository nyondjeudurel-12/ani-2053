#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

int main()
{
    // Déclaration des trois listes
    std::vector<std::string> avant;
    std::unordered_set<std::string> corrige;
    std::unordered_set<std::string> apres;

    std::string mot;
    int nombre;

    // Lecture de la liste AVANT
    std::cin >> mot >> nombre;

    for (int i = 0; i < nombre; ++i)
    {
        std::string cle;
        std::cin >> cle;
        avant.push_back(cle);
    }

    // Lecture de la liste CORRIGE
    std::cin >> mot >> nombre;

    for (int i = 0; i < nombre; ++i)
    {
        std::string cle;
        std::cin >> cle;
        corrige.insert(cle);
    }

    // Lecture de la liste APRES
    std::cin >> mot >> nombre;

    for (int i = 0; i < nombre; ++i)
    {
        std::string cle;
        std::cin >> cle;
        apres.insert(cle);
    }

    // Déclaration des compteurs
    int vraies = 0;
    int fausses = 0;
    int oubliees = 0;
    int nouvelles = 0;

    // Analyse de chaque clé de la liste AVANT
    for (std::size_t i = 0; i < avant.size(); ++i)
    {
        const std::string& cle = avant[i];

        // Une clé corrigée est prioritaire
        if (corrige.find(cle) != corrige.end())
        {
            std::cout << i + 1 << " " << cle
                      << " DEVENUE_FAUSSE\n";
            ++fausses;
        }
        // Sinon, on vérifie si elle existe encore dans APRES
        else if (apres.find(cle) != apres.end())
        {
            std::cout << i + 1 << " " << cle
                      << " ENCORE_VRAIE\n";
            ++vraies;
        }
        // Si elle n'est dans aucune des deux listes, elle est oubliée
        else
        {
            std::cout << i + 1 << " " << cle
                      << " OUBLIEE\n";
            ++oubliees;
        }
    }

    // Comptage des nouvelles clés présentes dans APRES
    for (const std::string& cle : apres)
    {
        if (std::find(avant.begin(), avant.end(), cle) == avant.end())
        {
            ++nouvelles;
        }
    }

    // Calcul de la part des manques oubliés
    int partOubliee = 0;
    int total = vraies + oubliees;

    if (total > 0)
    {
        partOubliee = (100 * oubliees) / total;
    }

    // Affichage des résultats
    std::cout << "VRAIES " << vraies << '\n';
    std::cout << "FAUSSES " << fausses << '\n';
    std::cout << "OUBLIEES " << oubliees << '\n';
    std::cout << "NOUVELLES " << nouvelles << '\n';
    std::cout << "PART_OUBLIEE " << partOubliee << '\n';

    return 0;
}
