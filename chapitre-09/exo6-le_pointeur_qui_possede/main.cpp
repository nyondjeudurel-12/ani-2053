#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Instruction
{
    std::string commande;
    std::string a;
    std::string b;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<Instruction> instructions;
    std::vector<int> lignesCopy;

    // Lecture de toutes les instructions avant leur exécution.
    for (int i = 1; i <= n; ++i)
    {
        Instruction instruction;
        std::cin >> instruction.commande >> instruction.a;

        if (instruction.commande == "MOVE" ||
            instruction.commande == "COPY")
        {
            std::cin >> instruction.b;
        }

        if (instruction.commande == "COPY")
            lignesCopy.push_back(i);

        instructions.push_back(instruction);
    }

    // Une seule copie invalide tout le programme.
    if (!lignesCopy.empty())
    {
        for (int ligne : lignesCopy)
            std::cout << "REFUSE " << ligne << '\n';

        return 0;
    }

    // Chaque variable possède un numéro d'objet ou zéro si elle est nulle.
    std::unordered_map<std::string, int> variables;

    // Conserve l'ordre de première apparition des variables.
    std::vector<std::string> ordreVariables;

    int nombreCrees = 0;
    int nombreDetruits = 0;
    int nombreNuls = 0;

    // Récupère une variable et l'enregistre lors de sa première apparition.
    auto obtenirVariable = [&](const std::string& nom) -> int&
    {
        auto it = variables.find(nom);

        if (it == variables.end())
        {
            ordreVariables.push_back(nom);
            it = variables.emplace(nom, 0).first;
        }

        return it->second;
    };

    // Détruit un objet s'il existe.
    auto detruire = [&](int objet)
    {
        if (objet != 0)
        {
            std::cout << "DETRUIT " << objet << '\n';
            ++nombreDetruits;
        }
    };

    // Exécution des instructions dans leur ordre de lecture.
    for (int i = 0; i < n; ++i)
    {
        const Instruction& instruction = instructions[i];

        if (instruction.commande == "NEW")
        {
            int& destination = obtenirVariable(instruction.a);

            // Créer un nouvel objet.
            ++nombreCrees;
            int nouvelObjet = nombreCrees;

            // Détruire l'ancien objet éventuellement possédé.
            detruire(destination);

            // La variable reçoit le nouvel objet.
            destination = nouvelObjet;
        }
        else if (instruction.commande == "MOVE")
        {
            int& source = obtenirVariable(instruction.a);
            int& destination = obtenirVariable(instruction.b);

            // Récupérer l'objet de la source.
            int objet = source;

            // La source devient nulle.
            source = 0;

            // L'ancien objet de la destination est détruit.
            detruire(destination);

            // La destination récupère l'objet déplacé.
            destination = objet;
        }
        else if (instruction.commande == "RESET")
        {
            int& variable = obtenirVariable(instruction.a);

            // Détruire l'objet et rendre la variable nulle.
            detruire(variable);
            variable = 0;
        }
        else if (instruction.commande == "USE")
        {
            int& variable = obtenirVariable(instruction.a);

            // Signaler l'utilisation d'une variable nulle.
            if (variable == 0)
            {
                std::cout << "NUL " << i + 1
                          << " " << instruction.a << '\n';

                ++nombreNuls;
            }
        }
    }

    // Détruire les objets restants dans l'ordre inverse d'apparition.
    for (int i = static_cast<int>(ordreVariables.size()) - 1; i >= 0; --i)
    {
        int& variable = variables[ordreVariables[i]];

        detruire(variable);
        variable = 0;
    }

    // Afficher le bilan final.
    std::cout << "CREES " << nombreCrees << '\n';
    std::cout << "DETRUITS " << nombreDetruits << '\n';
    std::cout << "NULS " << nombreNuls << '\n';

    return 0;
}