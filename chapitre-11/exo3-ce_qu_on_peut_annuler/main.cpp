#include <iostream>
#include <vector>
#include <string>

int main()
{
    // Pile des opérations attendues par l'utilisateur
    std::vector<std::string> operations;

    // Liste des traits présents dans l'outil
    std::vector<int> traits;

    // Compteur pour numéroter les traits
    int numeroTrait = 0;

    // Compteurs des statistiques
    int justes = 0;
    int riens = 0;
    int trahis = 0;
    int annulables = 0;
    int operationsTotales = 0;
    int numeroAnnulation = 0;

    std::string commande;

    // Lecture des commandes jusqu'à la fin de l'entrée
    while (std::cin >> commande)
    {
        if (commande == "ANNULE")
        {
            ++numeroAnnulation;

            // Déterminer ce que l'utilisateur attend
            std::string attendu = "AUCUNE";

            if (!operations.empty())
            {
                attendu = operations.back();
                operations.pop_back();
            }

            // Déterminer ce que l'outil effectue
            std::string obtenu = "RIEN";

            if (!traits.empty())
            {
                obtenu = "TRAIT " + std::to_string(traits.back());
                traits.pop_back();
            }

            // Déterminer le verdict
            std::string verdict;

            if (attendu == "AUCUNE" && obtenu == "RIEN")
            {
                verdict = "JUSTE";
                ++justes;
            }
            else if (obtenu == "RIEN")
            {
                verdict = "RIEN";
                ++riens;
            }
            else if (attendu == obtenu)
            {
                verdict = "JUSTE";
                ++justes;
            }
            else
            {
                verdict = "TRAHI";
                ++trahis;
            }

            // Affichage du résultat de l'annulation
            std::cout << "ANNULE " << numeroAnnulation
                      << " ATTENDU " << attendu
                      << " OBTENU " << obtenu
                      << " " << verdict << '\n';
        }
        else if (commande == "TRAIT")
        {
            // Création et numérotation d'un nouveau trait
            ++numeroTrait;

            operations.push_back(
                "TRAIT " + std::to_string(numeroTrait)
            );

            traits.push_back(numeroTrait);

            ++operationsTotales;
            ++annulables;
        }
        else if (commande == "EFFACE")
        {
            // L'opération entre dans la pile de l'utilisateur
            operations.push_back("EFFACE");

            // L'outil efface tous les traits
            traits.clear();

            ++operationsTotales;
        }
        else if (commande == "RANGE")
        {
            operations.push_back("RANGE");
            ++operationsTotales;
        }
        else
        {
            // Lecture du nom associé à l'image
            std::string nom;
            std::cin >> nom;

            // Construction de l'opération complète
            operations.push_back(commande + " " + nom);

            ++operationsTotales;
        }
    }

    // Calcul des statistiques finales
    std::cout << "JUSTES " << justes << '\n';
    std::cout << "RIENS " << riens << '\n';
    std::cout << "TRAHIS " << trahis << '\n';

    std::cout << "ANNULABLES " << annulables
              << " SUR " << operationsTotales << '\n';

    return 0;
}
