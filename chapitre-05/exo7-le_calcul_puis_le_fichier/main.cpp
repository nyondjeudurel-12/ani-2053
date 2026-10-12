#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Cette structure permet de garder les informations de chaque son.
struct Son
{
    string nom;
    long long frequence;
    long long canaux;
    long long bits;
    long long duree;
    long long fichier;
};

int main()
{
    long long S;
    int N;

    // On lit le seuil de memoire et le nombre de sons.
    if (!(cin >> S >> N))
    {
        return 0;
    }

    vector<Son> sons;
    sons.reserve(static_cast<size_t>(N));

    // On recupere les informations de tous les sons.
    for (int i = 0; i < N; ++i)
    {
        Son son;

        cin >> son.nom
            >> son.frequence
            >> son.canaux
            >> son.bits
            >> son.duree
            >> son.fichier;

        sons.push_back(son);
    }

    long long totalMemoire = 0;
    int totalFlux = 0;
    int totalRefuses = 0;

    // On traite les sons dans l'ordre de lecture.
    for (const Son& son : sons)
    {
        // On refuse les profondeurs qui ne sont pas autorisees.
        if (son.bits != 8 && son.bits != 16
            && son.bits != 24 && son.bits != 32)
        {
            cout << son.nom << " REFUSE\n";
            ++totalRefuses;
            continue;
        }
        // On calcule la taille brute en octets.
        // Les multiplications sont faites avant la division par 1000.
        long long brut = son.frequence
                       * son.canaux
                       * (son.bits / 8)
                       * son.duree / 1000;

        // On calcule la part du fichier par rapport a la taille brute.
        long long pourcent = son.fichier * 100 / brut;

        // Si la taille brute depasse le seuil, le son sera lu en flux.
        if (brut > S)
        {
            cout << son.nom << ' '
                 << brut << ' '
                 << pourcent << " FLUX\n";

            ++totalFlux;
        }
        else
        {
            // Sinon, le son est charge entierement en memoire.
            cout << son.nom << ' '
                 << brut << ' '
                 << pourcent << " MEMOIRE\n";

            totalMemoire += brut;
        }
    }

    // On affiche le bilan final.
    cout << "MEMOIRE " << totalMemoire << '\n';
    cout << "FLUX " << totalFlux << '\n';
    cout << "REFUSES " << totalRefuses << '\n';

    return 0;
}