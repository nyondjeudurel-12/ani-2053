#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Convertit un nombre de secondes en minutes:secondes.
string formaterTemps(long long secondes)
{
    ostringstream resultat;

    resultat << secondes / 60 << ':'
             << setw(2) << setfill('0') << secondes % 60;

    return resultat.str();
}

int main()
{
    string ligne;

    // Informations de la tâche actuellement en cours.
    bool enCours = false;
    string nom;
    long long minimum = 0;
    long long parJour = 0;
    long long debut = 0;
    long long gestes = 0;
    long long attente = 0;

    // Somme des coûts journaliers des tâches terminées.
    long long totalJour = 0;

    // Lecture du journal jusqu'à la fin de l'entrée.
    while (getline(cin, ligne))
    {
        istringstream entree(ligne);

        long long instant;
        string commande;

        // Ignore une ligne qui ne contient pas les informations attendues.
        if (!(entree >> instant >> commande))
        {
            continue;
        }

        if (commande == "DEBUT")
        {
            // Initialise une nouvelle tâche.
            entree >> nom >> minimum >> parJour;

            enCours = true;
            debut = instant;
            gestes = 0;
            attente = 0;
        }
        else if (commande == "FIN")
        {
            string nomFin;
            entree >> nomFin;

            if (enCours)
            {
                // Calcule les gestes supplémentaires sans valeur négative.
                long long enTrop = max(0LL, gestes - minimum);

                // Calcule la durée totale de la tâche.
                long long duree = instant - debut;

                // Convertit l'attente quotidienne en secondes entières.
                long long jour = (attente * parJour) / 1000;

                // Affiche les résultats de la tâche terminée.
                cout << nom
                     << " GESTES " << gestes
                     << " EN_TROP " << enTrop
                     << " DUREE " << duree
                     << " ATTENTE " << attente
                     << " JOUR " << formaterTemps(jour)
                     << '\n';

                // Ajoute le coût de cette tâche au total journalier.
                totalJour += jour;

                enCours = false;
            }
        }
        else if (commande == "ATTENTE")
        {
            long long dureeAttente;
            entree >> dureeAttente;

            // Une attente est comptée uniquement pendant une tâche.
            if (enCours)
            {
                attente += dureeAttente;
            }
        }
        else if (commande == "CLIC"
              || commande == "TOUCHE"
              || commande == "MOLETTE"
              || commande == "GLISSE")
        {
            // Chaque événement de ce type compte comme un geste.
            if (enCours)
            {
                ++gestes;
            }
        }
    }

    // Signale une tâche qui n'a pas reçu d'événement FIN.
    if (enCours)
    {
        cout << nom << " INACHEVEE\n";
    }

    // Affiche toujours le total, même si aucune tâche n'est terminée.
    cout << "TOTAL_JOUR " << formaterTemps(totalJour) << '\n';

    return 0;
}
