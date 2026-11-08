#include <iostream>
#include <vector>
#include <string>

// Représente une texture créée pendant l'exécution.
struct Texture
{
    int numero;
    bool liberee = false;
};

int main()
{
    int S, V, F;

    // Lecture du nombre de libérations dans chaque endroit.
    std::cin >> S >> V >> F;

    int N;
    std::cin >> N;

    std::vector<Texture> textures;
    std::vector<int> tableau;

    int nombreCreees = 0;

    // Fonction qui libère une texture un certain nombre de fois.
    auto liberer = [&](int numero, int repetitions, const std::string& moment)
    {
        for (int i = 0; i < repetitions; ++i)
        {
            Texture& texture = textures[numero - 1];

            // Une deuxième libération provoque un plantage.
            if (texture.liberee)
            {
                std::cout << "PLANTAGE " << moment
                          << " TEXTURE " << numero << '\n';
                return false;
            }

            texture.liberee = true;
        }

        return true;
    };

    // Lecture et exécution des opérations.
    for (int operation = 1; operation <= N; ++operation)
    {
        std::string commande;
        std::cin >> commande;

        if (commande == "AJOUTE")
        {
            ++nombreCreees;

            Texture nouvelle;
            nouvelle.numero = nombreCreees;
            nouvelle.liberee = false;

            textures.push_back(nouvelle);
            tableau.push_back(nombreCreees);
        }
        else if (commande == "SUPPRIME")
        {
            int index;
            std::cin >> index;

            int numero = tableau[index];

            // Libération de la texture supprimée.
            if (!liberer(numero, S, std::to_string(operation)))
                return 0;

            // Retrait de la texture : les index suivants reculent.
            tableau.erase(tableau.begin() + index);
        }
        else if (commande == "VIDE")
        {
            // Libération de toutes les textures dans l'ordre.
            for (int numero : tableau)
            {
                if (!liberer(numero, V, std::to_string(operation)))
                    return 0;
            }

            tableau.clear();
        }
    }

    // Libération des textures restantes à la fin du programme.
    for (int numero : tableau)
    {
        if (!liberer(numero, F, "FIN"))
            return 0;
    }

    // Recherche des textures qui n'ont jamais été libérées.
    std::vector<int> perdues;

    for (const Texture& texture : textures)
    {
        if (!texture.liberee)
            perdues.push_back(texture.numero);
    }

    // Affichage du bilan final.
    std::cout << "CREEES " << nombreCreees << '\n';
    std::cout << "FUITES " << perdues.size() << '\n';

    std::cout << "PERDUES";

    if (perdues.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (int numero : perdues)
            std::cout << " " << numero;
    }

    std::cout << '\n';

    return 0;
}