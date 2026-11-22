#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Découpe une chaîne en conservant les champs vides.
vector<string> decouper(const string& texte, char separateur)
{
    vector<string> champs;
    size_t debut = 0;

    while (true)
    {
        size_t position = texte.find(separateur, debut);

        if (position == string::npos)
        {
            champs.push_back(texte.substr(debut));
            break;
        }

        champs.push_back(texte.substr(debut, position - debut));
        debut = position + 1;
    }

    return champs;
}

// Convertit une chaîne en entier sans accepter de caractères supplémentaires.
bool lireEntier(const string& texte, long long& valeur)
{
    if (texte.empty())
    {
        return false;
    }

    try
    {
        size_t position = 0;
        long long nombre = stoll(texte, &position);

        if (position != texte.size())
        {
            return false;
        }

        valeur = nombre;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

// Contient les événements prévus pour un même tour.
struct Tour
{
    vector<string> pan;
    vector<string> zoom;
    vector<string> depot;
    vector<string> clic;
    vector<string> move;
    vector<string> range;
    vector<string> grille;
    vector<string> capture;
};

// Affiche les événements d'une catégorie dans leur ordre.
void afficher(const vector<string>& actions, long long tour)
{
    for (const string& action : actions)
    {
        cout << "TOUR " << tour << " " << action << '\n';
    }
}

int main()
{
    map<long long, Tour> scenario;

    // Conserve les numéros pour calculer les événements jamais exécutés.
    vector<long long> toursActions;
    vector<long long> toursCaptures;

    long long sortie = 0;
    bool sortiePresente = false;

    long long ignores = 0;

    string ligne;

    // Lit toutes les variables jusqu'à la fin de l'entrée.
    while (getline(cin, ligne))
    {
        size_t egal = ligne.find('=');

        // Une ligne sans signe égal est mal formée.
        if (egal == string::npos)
        {
            ++ignores;
            continue;
        }

        string nomVariable = ligne.substr(0, egal);
        string valeur = ligne.substr(egal + 1);

        // CAPTURES
        if (nomVariable == "NK_AGENT_SHOT")
        {
            vector<string> elements = decouper(valeur, ',');

            int gardes = 0;

            for (const string& element : elements)
            {
                long long numero;

                if (!lireEntier(element, numero))
                {
                    ++ignores;
                    continue;
                }

                if (gardes >= 8)
                {
                    ++ignores;
                    continue;
                }

                ++gardes;
                toursCaptures.push_back(numero);

                // Une capture du numéro n se produit au tour n - 1.
                if (numero > 0)
                {
                    scenario[numero - 1].capture.push_back("CAPTURE");
                }
            }
        }

        // SORTIE
        else if (nomVariable == "NK_AGENT_EXIT")
        {
            if (!lireEntier(valeur, sortie))
            {
                ++ignores;
            }
            else
            {
                sortiePresente = true;
            }
        }

        // DEPLACEMENT DE LA VUE
        else if (nomVariable == "NK_AGENT_PAN")
        {
            vector<string> champs = decouper(valeur, ':');
            long long numero;

            if (champs.size() < 3 || !lireEntier(champs[0], numero))
            {
                ++ignores;
            }
            else
            {
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].pan.push_back(
                        "PAN " + champs[1] + " " + champs[2]);
                }
            }
        }

        // ZOOM
        else if (nomVariable == "NK_AGENT_ZOOM")
        {
            vector<string> champs = decouper(valeur, ':');
            long long numero;

            if (champs.size() < 4 || !lireEntier(champs[0], numero))
            {
                ++ignores;
            }
            else
            {
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].zoom.push_back(
                        "ZOOM " + champs[1] + " " +
                        champs[2] + " " + champs[3]);
                }
            }
        }

        // DEPOTS D'IMAGES
        else if (nomVariable == "NK_AGENT_DROP")
        {
            vector<string> elements = decouper(valeur, ';');
            int gardes = 0;

            for (const string& element : elements)
            {
                size_t premier = element.find(':');
                size_t deuxieme = element.find(':', premier == string::npos
                                                       ? 0 : premier + 1);
                size_t troisieme = element.find(':', deuxieme == string::npos
                                                        ? 0 : deuxieme + 1);

                long long numero;

                // Le dépôt doit contenir trois séparateurs au minimum.
                if (premier == string::npos ||
                    deuxieme == string::npos ||
                    troisieme == string::npos ||
                    !lireEntier(element.substr(0, premier), numero))
                {
                    ++ignores;
                    continue;
                }

                if (gardes >= 8)
                {
                    ++ignores;
                    continue;
                }

                ++gardes;
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    string px = element.substr(
                        premier + 1, deuxieme - premier - 1);

                    string py = element.substr(
                        deuxieme + 1, troisieme - deuxieme - 1);

                    // Tout ce qui suit le troisième deux-points est le chemin.
                    string chemin = element.substr(troisieme + 1);

                    scenario[numero].depot.push_back(
                        "DEPOT " + chemin + " " + px + " " + py);
                }
            }
        }

        // CLICS
        else if (nomVariable == "NK_AGENT_CLICK")
        {
            vector<string> elements = decouper(valeur, ';');
            int gardes = 0;

            for (const string& element : elements)
            {
                vector<string> champs = decouper(element, ':');
                long long numero;

                if (champs.size() < 3 ||
                    !lireEntier(champs[0], numero))
                {
                    ++ignores;
                    continue;
                }

                if (gardes >= 8)
                {
                    ++ignores;
                    continue;
                }

                ++gardes;
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].clic.push_back(
                        "CLIC " + champs[1] + " " + champs[2]);
                }
            }
        }

        // DEPLACEMENT DE LA SELECTION
        else if (nomVariable == "NK_AGENT_MOVE")
        {
            vector<string> champs = decouper(valeur, ':');
            long long numero;

            if (champs.size() < 3 || !lireEntier(champs[0], numero))
            {
                ++ignores;
            }
            else
            {
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].move.push_back(
                        "MOVE " + champs[1] + " " + champs[2]);
                }
            }
        }

        // RANGEMENT
        else if (nomVariable == "NK_AGENT_PACK")
        {
            long long numero;

            if (!lireEntier(valeur, numero))
            {
                ++ignores;
            }
            else
            {
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].range.push_back("RANGE");
                }
            }
        }

        // GRILLE
        else if (nomVariable == "NK_AGENT_GRID")
        {
            vector<string> champs = decouper(valeur, ':');
            long long numero;

            if (champs.size() < 2 || !lireEntier(champs[0], numero))
            {
                ++ignores;
            }
            else
            {
                toursActions.push_back(numero);

                if (numero > 0)
                {
                    scenario[numero].grille.push_back(
                        "GRILLE " + champs[1]);
                }
            }
        }

        // Toute variable inconnue est ignorée.
        else
        {
            ++ignores;
        }
    }

    // Parcourt les tours dans l'ordre chronologique.
    for (const auto& entree : scenario)
    {
        long long tour = entree.first;
        const Tour& actions = entree.second;

        // Après la sortie, aucun nouveau tour n'est joué.
        if (sortiePresente && sortie > 0 && tour >= sortie)
        {
            continue;
        }

        // Respecte l'ordre imposé par l'énoncé.
        afficher(actions.pan, tour);
        afficher(actions.zoom, tour);
        afficher(actions.depot, tour);
        afficher(actions.clic, tour);
        afficher(actions.move, tour);
        afficher(actions.range, tour);
        afficher(actions.grille, tour);
        afficher(actions.capture, tour);
    }

    // Compte les actions qui n'ont jamais été exécutées.
    long long jamais = 0;

    for (long long numero : toursActions)
    {
        if (numero <= 0 || (sortiePresente && sortie > 0 &&
                            numero >= sortie))
        {
            ++jamais;
        }
    }

    // Une capture du numéro de sortie a bien lieu avant l'arrêt.
    for (long long numero : toursCaptures)
    {
        if (numero <= 0 || (sortiePresente && sortie > 0 &&
                            numero > sortie))
        {
            ++jamais;
        }
    }

    // Affiche les informations finales.
    if (sortiePresente && sortie > 0)
    {
        cout << "ARRET " << sortie - 1 << '\n';
    }
    else
    {
        cout << "SANS_ARRET\n";
    }

    cout << "JAMAIS " << jamais << '\n';
    cout << "IGNORES " << ignores << '\n';

    return 0;
}
