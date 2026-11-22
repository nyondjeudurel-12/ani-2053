
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Convertit un instant mm:ss en nombre total de secondes.
int convertirTemps(const string& temps)
{
    size_t separateur = temps.find(':');

    int minutes = stoi(temps.substr(0, separateur));
    int secondes = stoi(temps.substr(separateur + 1));

    return minutes * 60 + secondes;
}

// Regroupe les informations d'un contournement observé.
struct Contournement
{
    string nom;
    int fois = 0;
    int premiereObservation = 0;
    int ordreEntree = 0;
    bool dit = false;
};

int main()
{
    int nombreObservations;
    string mot;

    // Lit le nombre d'observations.
    cin >> mot >> nombreObservations;

    vector<Contournement> contournements;

    // Associe chaque nom à sa position dans le vecteur.
    map<string, int> positions;

    int horsSeance = 0;
    int ordre = 0;

    // Lit toutes les observations.
    for (int i = 0; i < nombreObservations; ++i)
    {
        string temps;
        string nom;

        cin >> temps >> nom;

        int secondes = convertirTemps(temps);

        // Les observations après 20 minutes sont écartées.
        if (secondes > 20 * 60)
        {
            ++horsSeance;
            continue;
        }

        // Recherche si le contournement a déjà été observé.
        auto position = positions.find(nom);

        if (position == positions.end())
        {
            // Crée un nouveau contournement.
            Contournement nouveau;

            nouveau.nom = nom;
            nouveau.fois = 1;
            nouveau.premiereObservation = secondes;
            nouveau.ordreEntree = ordre++;

            positions[nom] = static_cast<int>(contournements.size());
            contournements.push_back(nouveau);
        }
        else
        {
            // Met à jour un contournement déjà rencontré.
            Contournement& existant =
                contournements[position->second];

            ++existant.fois;

            // Garde l'instant le plus ancien.
            if (secondes < existant.premiereObservation)
            {
                existant.premiereObservation = secondes;
            }
        }
    }

    // Lit les noms cités pendant l'entretien.
    int nombreCites;
    cin >> mot >> nombreCites;

    set<string> nomsCites;
    vector<string> ordreCitations;

    for (int i = 0; i < nombreCites; ++i)
    {
        string nom;
        cin >> nom;

        nomsCites.insert(nom);
        ordreCitations.push_back(nom);
    }

    // Vérifie quels contournements ont été déclarés.
    for (Contournement& contournement : contournements)
    {
        contournement.dit =
            nomsCites.find(contournement.nom) != nomsCites.end();
    }

    // Trie les contournements selon les trois critères demandés.
    sort(contournements.begin(), contournements.end(),
         [](const Contournement& a, const Contournement& b)
         {
             if (a.fois != b.fois)
             {
                 return a.fois > b.fois;
             }

             if (a.premiereObservation != b.premiereObservation)
             {
                 return a.premiereObservation < b.premiereObservation;
             }

             return a.ordreEntree < b.ordreEntree;
         });

    int nonDits = 0;
    int totalObservations = 0;
    int observationsNonDites = 0;

    // Affiche les contournements et calcule les statistiques.
    for (const Contournement& contournement : contournements)
    {
        cout << contournement.nom
             << " fois " << contournement.fois
             << (contournement.dit ? " DIT" : " NON_DIT")
             << '\n';

        totalObservations += contournement.fois;

        if (!contournement.dit)
        {
            ++nonDits;
            observationsNonDites += contournement.fois;
        }
    }

    // Calcule le pourcentage des observations non déclarées.
    int partNonDite = 0;

    if (totalObservations > 0)
    {
        partNonDite =
            (100 * observationsNonDites) / totalObservations;
    }

    cout << "NON_DITS " << nonDits << '\n';
    cout << "PART_NON_DITE " << partNonDite << '\n';

    // Recherche les noms cités mais jamais observés pendant la séance.
    vector<string> ditsSansVu;

    for (const string& nom : ordreCitations)
    {
        if (positions.find(nom) == positions.end())
        {
            ditsSansVu.push_back(nom);
        }
    }

    cout << "DIT_SANS_VU";

    if (ditsSansVu.empty())
    {
        cout << " AUCUN";
    }
    else
    {
        for (const string& nom : ditsSansVu)
        {
            cout << " " << nom;
        }
    }

    cout << '\n';

    // Affiche le nombre d'observations hors séance.
    cout << "HORS_SEANCE " << horsSeance << '\n';

    return 0;
}
