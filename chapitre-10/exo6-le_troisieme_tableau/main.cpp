#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Vérifie si un tableau doit répéter une opération.
bool contient(const std::vector<std::string>& noms,
              const std::string& nom)
{
    return std::find(noms.begin(), noms.end(), nom) != noms.end();
}

// Lit les noms des tableaux concernés par une opération.
std::vector<std::string> lireTableaux(const std::string& ligne)
{
    std::istringstream flux(ligne);
    std::string operation;
    std::string nom;
    std::vector<std::string> tableaux;

    flux >> operation;

    while (flux >> nom)
    {
        tableaux.push_back(nom);
    }

    return tableaux;
}

// Supprime un élément si son index existe.
void supprimerIndex(std::vector<std::string>& tableau, int index)
{
    if (index >= 0 && index < static_cast<int>(tableau.size()))
    {
        tableau.erase(tableau.begin() + index);
    }
}

// Échange deux éléments si les deux index existent.
void echangerIndex(std::vector<std::string>& tableau,
                   int premier,
                   int second)
{
    if (premier >= 0 && second >= 0
        && premier < static_cast<int>(tableau.size())
        && second < static_cast<int>(tableau.size()))
    {
        std::swap(tableau[premier], tableau[second]);
    }
}

int main()
{
    std::string ligne;

    // Lecture des trois configurations.
    std::getline(std::cin, ligne);
    const std::vector<std::string> ajout = lireTableaux(ligne);

    std::getline(std::cin, ligne);
    const std::vector<std::string> suppression = lireTableaux(ligne);

    std::getline(std::cin, ligne);
    const std::vector<std::string> echange = lireTableaux(ligne);

    int n;
    std::cin >> n;

    std::vector<std::string> modele;
    std::vector<std::string> textures;
    std::vector<std::string> sources;

    // Exécution des opérations du modèle.
    for (int operation = 0; operation < n; ++operation)
    {
        std::string type;
        std::cin >> type;

        if (type == "AJOUTE")
        {
            std::string nom;
            std::cin >> nom;

            // Le modèle reçoit toujours l'image.
            modele.push_back(nom);

            // Les autres tableaux suivent selon la configuration.
            if (contient(ajout, "textures"))
            {
                textures.push_back(nom);
            }

            if (contient(ajout, "sources"))
            {
                sources.push_back(nom);
            }
        }
        else if (type == "SUPPRIME")
        {
            int c;
            std::cin >> c;

            std::vector<int> indices(c);

            for (int i = 0; i < c; ++i)
            {
                std::cin >> indices[i];
            }

            // Suppression du plus grand index au plus petit.
            for (int i = c - 1; i >= 0; --i)
            {
                const int index = indices[i];

                supprimerIndex(modele, index);

                if (contient(suppression, "textures"))
                {
                    supprimerIndex(textures, index);
                }

                if (contient(suppression, "sources"))
                {
                    supprimerIndex(sources, index);
                }
            }
        }
        else if (type == "MONTE")
        {
            int index;
            std::cin >> index;

            // Un échange est possible si la voisine existe dans le modèle.
            if (index >= 0
                && index + 1 < static_cast<int>(modele.size()))
            {
                echangerIndex(modele, index, index + 1);

                if (contient(echange, "textures"))
                {
                    echangerIndex(textures, index, index + 1);
                }

                if (contient(echange, "sources"))
                {
                    echangerIndex(sources, index, index + 1);
                }
            }
        }
        else if (type == "DESCEND")
        {
            int index;
            std::cin >> index;

            // Un échange est possible si la voisine existe dans le modèle.
            if (index > 0
                && index < static_cast<int>(modele.size()))
            {
                echangerIndex(modele, index, index - 1);

                if (contient(echange, "textures"))
                {
                    echangerIndex(textures, index, index - 1);
                }

                if (contient(echange, "sources"))
                {
                    echangerIndex(sources, index, index - 1);
                }
            }
        }
    }

    // Recherche de la longueur du plus long tableau.
    const std::size_t longueur = std::max({
        modele.size(),
        textures.size(),
        sources.size()
    });

    int decales = 0;

    // Affichage des trois tableaux alignés par index.
    for (std::size_t i = 0; i < longueur; ++i)
    {
        const std::string nomModele =
            i < modele.size() ? modele[i] : "-";

        const std::string nomTexture =
            i < textures.size() ? textures[i] : "-";

        const std::string nomSource =
            i < sources.size() ? sources[i] : "-";

        std::cout << i << " "
                  << nomModele << " "
                  << nomTexture << " "
                  << nomSource << '\n';

        // Une ligne est décalée si une case manque ou diffère.
        if (nomModele != nomTexture || nomModele != nomSource)
        {
            ++decales;
        }
    }

    std::cout << "DECALES " << decales << '\n';

    return 0;
}