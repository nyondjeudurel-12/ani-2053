#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Vérifie si un emploi exige la définition complète du type.
bool exigeDefinition(const std::string& emploi) {
    return emploi == "VALEUR" ||
           emploi == "BASE" ||
           emploi == "CORPS" ||
           emploi == "TAILLE";
}

int main() {
    int u;
    std::cin >> u;

    // Conserve les types dans leur ordre de première apparition.
    std::vector<std::string> ordreTypes;

    // Indique si chaque type nécessite sa définition complète.
    std::unordered_map<std::string, bool> types;

    for (int i = 0; i < u; ++i) {
        std::string nom;
        std::string emploi;

        std::cin >> nom >> emploi;

        // Ajoute le type uniquement lors de sa première apparition.
        if (types.find(nom) == types.end()) {
            ordreTypes.push_back(nom);
            types[nom] = false;
        }

        // Un seul emploi exigeant la définition suffit.
        if (exigeDefinition(emploi)) {
            types[nom] = true;
        }
    }

    int a;
    std::cin >> a;

    // Enregistre les types actuellement inclus dans l'en-tête.
    std::unordered_set<std::string> inclusActuellement;

    for (int i = 0; i < a; ++i) {
        std::string nom;
        std::cin >> nom;
        inclusActuellement.insert(nom);
    }

    int nombreInclure = 0;
    int nombreAnticiper = 0;
    int inclusionsRetirees = 0;

    // Affiche chaque type et calcule les différents compteurs.
    for (const std::string& nom : ordreTypes) {
        if (types[nom]) {
            std::cout << nom << " INCLURE\n";
            ++nombreInclure;
        } else {
            std::cout << nom << " ANTICIPER\n";
            ++nombreAnticiper;

            // Une inclusion ne peut être retirée que si elle existe déjà.
            if (inclusActuellement.find(nom) != inclusActuellement.end()) {
                ++inclusionsRetirees;
            }
        }
    }

    // Affiche le bilan final.
    std::cout << "INCLURE " << nombreInclure << '\n';
    std::cout << "ANTICIPER " << nombreAnticiper << '\n';
    std::cout << "INCLUSIONS_RETIREES " << inclusionsRetirees << '\n';

    return 0;
}
