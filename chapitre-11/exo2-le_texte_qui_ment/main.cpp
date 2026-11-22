#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

struct Commit
{
    std::string hash;
    std::string action;
    std::vector<std::string> fonctions;
};

struct Annonce
{
    std::string hash;
    std::string etat;
    std::string fonction;
};

int main()
{
    int nombreCommits;
    std::cin >> nombreCommits;

    // Stockage des commits
    std::vector<Commit> commits;

    // Position de chaque commit dans l'historique
    std::unordered_map<std::string, int> positions;

    // Lecture de l'historique
    for (int i = 0; i < nombreCommits; ++i)
    {
        Commit commit;
        int nombreFonctions;

        std::cin >> commit.hash >> commit.action >> nombreFonctions;

        for (int j = 0; j < nombreFonctions; ++j)
        {
            std::string fonction;
            std::cin >> fonction;
            commit.fonctions.push_back(fonction);
        }

        positions[commit.hash] = i;
        commits.push_back(commit);
    }

    // Calcul de l'état des fonctionnalités après chaque commit
    std::vector<std::unordered_set<std::string>> etats;
    std::unordered_set<std::string> presentes;

    for (const Commit& commit : commits)
    {
        for (const std::string& fonction : commit.fonctions)
        {
            if (commit.action == "AJOUTE")
            {
                presentes.insert(fonction);
            }
            else if (commit.action == "RETIRE")
            {
                presentes.erase(fonction);
            }
        }

        etats.push_back(presentes);
    }

    // Lecture des annonces
    int nombreAnnonces;
    std::cin >> nombreAnnonces;

    std::vector<Annonce> annonces;

    for (int i = 0; i < nombreAnnonces; ++i)
    {
        Annonce annonce;

        std::cin >> annonce.hash
                 >> annonce.etat
                 >> annonce.fonction;

        annonces.push_back(annonce);
    }

    // Vérification des annonces
    int mensonges = 0;

    for (std::size_t i = 0; i < annonces.size(); ++i)
    {
        const Annonce& annonce = annonces[i];

        int positionEcriture = positions[annonce.hash];

        // Vérifie si une fonction respecte l'annonce à un commit donné
        auto estVraie = [&](int position)
        {
            bool existe = etats[position].find(annonce.fonction)
                          != etats[position].end();

            if (annonce.etat == "A_VENIR")
            {
                return !existe;
            }

            return existe;
        };

        // Vérification au dernier commit
        int dernierCommit = nombreCommits - 1;

        if (estVraie(dernierCommit))
        {
            std::cout << "ANNONCE " << i + 1 << " VRAI\n";
        }
        else
        {
            ++mensonges;

            // Recherche du premier commit de mensonge continu
            int debutMensonge = dernierCommit;

            while (debutMensonge > positionEcriture
                   && !estVraie(debutMensonge - 1))
            {
                --debutMensonge;
            }

            std::cout << "ANNONCE " << i + 1
                      << " MENT "
                      << commits[debutMensonge].hash << '\n';
        }
    }

    // Affichage du nombre total de mensonges
    std::cout << "MENSONGES " << mensonges << '\n';

    return 0;
}