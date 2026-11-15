#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main()
{
    // Contient les identifiants des images dans leur ordre actuel.
    std::vector<int> ordre;

    // Compteurs demandés par l'exercice.
    int occasions = 0;
    int repercutes = 0;
    int recherches = 0;

    // Le prochain identifiant à attribuer.
    int prochainId = 1;

    int nombreOperations;
    std::cin >> nombreOperations;

    for (int operation = 0; operation < nombreOperations; ++operation)
    {
        std::string commande;
        std::cin >> commande;

        if (commande == "AJOUTE")
        {
            // Chaque nouvelle image reçoit un identifiant unique.
            ordre.push_back(prochainId);
            ++prochainId;
        }
        else if (commande == "SUPPRIME")
        {
            int nombre;
            std::cin >> nombre;

            std::vector<int> indices(nombre);

            // On lit tous les index à supprimer.
            for (int i = 0; i < nombre; ++i)
            {
                std::cin >> indices[i];
            }

            // Une occasion et deux gestes par image supprimée.
            ++occasions;
            repercutes += 2 * nombre;

            // On supprime de la fin vers le début pour conserver les index.
            for (int i = nombre - 1; i >= 0; --i)
            {
                ordre.erase(ordre.begin() + indices[i]);
            }
        }
        else if (commande == "MONTE")
        {
            int index;
            std::cin >> index;

            // L'image échange sa place avec celle qui la suit.
            if (static_cast<std::size_t>(index + 1) < ordre.size())
            {
                std::swap(ordre[index], ordre[index + 1]);

                ++occasions;
                repercutes += 2;
            }
        }
        else if (commande == "DESCEND")
        {
            int index;
            std::cin >> index;

            // L'image échange sa place avec celle qui la précède.
            if (index > 0)
            {
                std::swap(ordre[index], ordre[index - 1]);

                ++occasions;
                repercutes += 2;
            }
        }
        else if (commande == "DESSINE")
        {
            // Chaque image présente nécessite une recherche.
            recherches += static_cast<int>(ordre.size());
        }
    }

    // Affichage de l'ordre final.
    std::cout << "ORDRE";

    if (ordre.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (int id : ordre)
        {
            std::cout << " " << id;
        }
    }

    std::cout << '\n';

    // Affichage des trois compteurs.
    std::cout << "OCCASIONS " << occasions << '\n';
    std::cout << "REPERCUTES " << repercutes << '\n';
    std::cout << "RECHERCHES " << recherches << '\n';

    return 0;
}