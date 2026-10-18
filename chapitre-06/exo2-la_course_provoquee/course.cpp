#include <iostream>
#include <vector>
#include <NKThreading/NkThread.h>

using namespace nkentseu;
using namespace nkentseu::threading;

// Nombre de fils utilisés pour provoquer la course.
constexpr int NOMBRE_FILS = 8;
constexpr int INCREMENTS_PAR_FIL = 1000000;

int main()
{
    int compteur = 0;

    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_FILS);

    // Création des fils.
    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        fils.emplace_back([&compteur](void*)
        {
            for (int j = 0; j < INCREMENTS_PAR_FIL; ++j)
            {
                compteur += 1;
            }
        });
    }

    // Attente de la fin de tous les fils.
    for (auto& fil : fils)
    {
        fil.Join();
    }

    // Calcul du total attendu.
    const long long totalAttendu =
        static_cast<long long>(NOMBRE_FILS) * INCREMENTS_PAR_FIL;

    std::cout << "Nombre de fils : " << NOMBRE_FILS << '\n';
    std::cout << "Increments par fil : "
              << INCREMENTS_PAR_FIL << '\n';

    std::cout << "Total obtenu : " << compteur << '\n';
    std::cout << "Total attendu : " << totalAttendu << '\n';

    return 0;
}