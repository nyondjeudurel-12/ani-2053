#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long D, C;
    int N;

    // On lit la duree du son et le temps necessaire pour le charger.
    if (!(cin >> D >> C))
    {
        return 0;
    }

    // On recupere le nombre de lectures prevues.
    if (!(cin >> N))
    {
        return 0;
    }

    vector<long long> instants(N);

    // On enregistre les instants de chaque lecture.
    for (int i = 0; i < N; ++i)
    {
        cin >> instants[i];
    }

    // Ces variables servent a garder les valeurs maximales et les bilans.
    int voixMax = 0;
    long long retardMax = 0;
    int coupes = 0;

    // Cette variable indique quand le chargement precedent est termine.
    long long finChargementPrecedent = 0;

    // On traite chaque lecture dans l'ordre donne.
    for (int i = 0; i < N; ++i)
    {
        long long t = instants[i];

        // On compte les lectures qui sont encore actives a l'instant t.
        // Une lecture qui se termine exactement a t n'est plus active.
        int voix = 0;

        for (int j = 0; j <= i; ++j)
        {
            if (instants[j] + D > t)
            {
                ++voix;
            }
        }

        // On met a jour le nombre maximal de voix utilisees.
        voixMax = max(voixMax, voix);

        // Le chargement commence a t, sauf si le chargement precedent
        // n'est pas encore termine.
        long long debutChargement =
            max(t, finChargementPrecedent);

        long long finChargement = debutChargement + C;

        // Le retard correspond a la fin du chargement moins l'instant prevu.
        long long retard = finChargement - t;

        retardMax = max(retardMax, retard);

        // On garde la fin de ce chargement pour la lecture suivante.
        finChargementPrecedent = finChargement;

        // Avec une seule voix, la lecture est coupee si la suivante
        // commence avant la fin de celle-ci.
        bool coupe = false;

        if (i + 1 < N)
        {
            if (instants[i + 1] < t + D)
            {
                coupe = true;
            }
        }

        if (coupe)
        {
            cout << t << ' '
                 << voix << ' '
                 << retard << " COUPE\n";

            ++coupes;
        }
        else
        {
            cout << t << ' '
                 << voix << ' '
                 << retard << " ENTIER\n";
        }
    }

    // On affiche le bilan final des trois situations.
    cout << "VOIX_MAX " << voixMax << '\n';
    cout << "RETARD_MAX " << retardMax << '\n';
    cout << "COUPES " << coupes << '\n';

    return 0;
}