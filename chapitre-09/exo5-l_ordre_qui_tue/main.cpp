#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Objet
{
    std::string nom;
    bool libere = false;
};

struct Bloc
{
    std::vector<int> objets;
};

struct Dependance
{
    int a;
    int b;
};

int main()
{
    std::unordered_map<std::string, int> indices;
    std::vector<Objet> objets;
    std::vector<Dependance> dependances;
    std::vector<Bloc> blocs(1);

    std::string commande;

    // Libère un objet et vérifie toutes ses dépendances.
    auto liberer = [&](int index, const std::string& type) -> bool
    {
        Objet& objet = objets[index];

        // Un objet déjà libéré est simplement ignoré.
        if (objet.libere)
            return true;

        // Vérifier les dépendances dans leur ordre de lecture.
        for (const Dependance& dep : dependances)
        {
            if (dep.a == index && objets[dep.b].libere)
            {
                std::cout << "PLANTAGE " << objet.nom
                          << " " << objets[dep.b].nom << '\n';
                return false;
            }
        }

        objet.libere = true;
        std::cout << type << " " << objet.nom << '\n';

        return true;
    };

    // Lecture des instructions jusqu'à la fin de l'entrée.
    while (std::cin >> commande)
    {
        if (commande == "DECL")
        {
            std::string nom;
            std::cin >> nom;

            int index = static_cast<int>(objets.size());

            objets.push_back({nom, false});
            indices[nom] = index;

            // Ajouter l'objet au bloc courant.
            blocs.back().objets.push_back(index);
        }
        else if (commande == "DEPEND")
        {
            std::string nomA;
            std::string nomB;

            std::cin >> nomA >> nomB;

            dependances.push_back({
                indices.at(nomA),
                indices.at(nomB)
            });
        }
        else if (commande == "FERME")
        {
            std::string nom;
            std::cin >> nom;

            int index = indices.at(nom);

            // Libération immédiate de l'objet.
            if (!liberer(index, "FERME"))
                return 0;
        }
        else if (commande == "{")
        {
            // Ouverture d'un nouveau bloc.
            blocs.push_back({});
        }
        else if (commande == "}")
        {
            // Fermeture du bloc courant en ordre inverse.
            Bloc& bloc = blocs.back();

            for (int i = static_cast<int>(bloc.objets.size()) - 1; i >= 0; --i)
            {
                int index = bloc.objets[i];

                if (!liberer(index, "DETRUIT"))
                    return 0;
            }

            blocs.pop_back();
        }
    }

    // À la fin de l'entrée, fermer le bloc de la fonction.
    Bloc& fonction = blocs.front();

    for (int i = static_cast<int>(fonction.objets.size()) - 1; i >= 0; --i)
    {
        int index = fonction.objets[i];

        if (!liberer(index, "DETRUIT"))
            return 0;
    }

    std::cout << "PROPRE\n";

    return 0;
}