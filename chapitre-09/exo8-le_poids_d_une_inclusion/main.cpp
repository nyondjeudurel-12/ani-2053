#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Représente un fichier et les fichiers qu'il inclut.
struct Fichier {
    std::string nom;
    std::vector<std::string> inclus;
};

// Vérifie si un fichier est un .cpp.
bool estCpp(const std::string& nom) {
    return nom.size() >= 4 &&
           nom.substr(nom.size() - 4) == ".cpp";
}

// Vérifie si un fichier est un .h.
bool estHeader(const std::string& nom) {
    return nom.size() >= 2 &&
           nom.substr(nom.size() - 2) == ".h";
}

// Compte les fichiers .cpp qui dépendent du fichier modifié.
int compterRecompilations(
    int depart,
    const std::vector<Fichier>& fichiers,
    const std::vector<std::vector<int>>& dependants
) {
    int nombre = 0;

    // Chaque fichier ne sera visité qu'une seule fois.
    std::vector<bool> visite(fichiers.size(), false);
    std::vector<int> pile;

    pile.push_back(depart);
    visite[depart] = true;

    // Parcours de tous les fichiers dépendants.
    while (!pile.empty()) {
        int courant = pile.back();
        pile.pop_back();

        // Un fichier .cpp atteint doit être recompilé.
        if (estCpp(fichiers[courant].nom)) {
            ++nombre;
        }

        // Recherche des fichiers qui incluent le fichier courant.
        for (int suivant : dependants[courant]) {
            if (!visite[suivant]) {
                visite[suivant] = true;
                pile.push_back(suivant);
            }
        }
    }

    return nombre;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Fichier> fichiers(n);

    // Première lecture : noms et inclusions.
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> fichiers[i].nom >> k;

        fichiers[i].inclus.resize(k);

        for (int j = 0; j < k; ++j) {
            std::cin >> fichiers[i].inclus[j];
        }
    }

    // Associe chaque nom de fichier à son indice.
    std::unordered_map<std::string, int> indices;

    for (int i = 0; i < n; ++i) {
        indices[fichiers[i].nom] = i;
    }

    // Construit le graphe inversé :
    // un fichier pointe vers ceux qui l'incluent.
    std::vector<std::vector<int>> dependants(n);

    for (int i = 0; i < n; ++i) {
        for (const std::string& nomInclus : fichiers[i].inclus) {
            auto it = indices.find(nomInclus);

            // Les fichiers absents de la liste sont ignorés.
            if (it != indices.end()) {
                dependants[it->second].push_back(i);
            }
        }
    }

    int q;
    std::cin >> q;

    // Traite chaque question dans l'ordre.
    for (int i = 0; i < q; ++i) {
        std::string nom;
        std::cin >> nom;

        int indice = indices[nom];

        int resultat = compterRecompilations(
            indice, fichiers, dependants
        );

        std::cout << nom << " " << resultat << '\n';
    }

    // Recherche du .h le plus coûteux à modifier.
    std::string plusLourd = "AUCUN";
    int maximum = -1;

    for (int i = 0; i < n; ++i) {
        if (estHeader(fichiers[i].nom)) {
            int resultat = compterRecompilations(
                i, fichiers, dependants
            );

            // Le strictement supérieur conserve le premier en cas d'égalité.
            if (resultat > maximum) {
                maximum = resultat;
                plusLourd = fichiers[i].nom;
            }
        }
    }

    if (plusLourd == "AUCUN") {
        std::cout << "PLUS_LOURD AUCUN\n";
    } else {
        std::cout << "PLUS_LOURD "
                  << plusLourd << " " << maximum << '\n';
    }

    return 0;
}
