#include <iostream>

#include <NKThreading/NkThread.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKTime/NkChrono.h>

using namespace nkentseu;
using namespace nkentseu::threading;

// VERSION QUI SE FIGE
// ----------------------------------------------------------------------------
// Dans cette version, le fil a prend m1 puis m2, tandis que le fil b prend
// m2 puis m1. Les deux fils peuvent donc attendre chacun un verrou détenu
// par l'autre.
//
// Fil a :
// void FonctionA(NkMutex& m1, NkMutex& m2)
// {
//     NkScopedLock<NkMutex> verrou1(m1);
//     NkChrono::SleepMilliseconds(100);
//     NkScopedLock<NkMutex> verrou2(m2);
// }
//
// Fil b :
// void FonctionB(NkMutex& m1, NkMutex& m2)
// {
//     NkScopedLock<NkMutex> verrou2(m2);
//     NkChrono::SleepMilliseconds(100);
//     NkScopedLock<NkMutex> verrou1(m1);
// }
//

// Les deux fonctions prennent maintenant les mutex dans le même ordre : m1,
// puis m2. Cela empêche l'interblocage entre ces deux fonctions.

void FonctionA(NkMutex& m1, NkMutex& m2)
{
    nkentseu::threading::NkScopedLock<NkMutex> verrou1(m1);

    std::cout << "Fil a : verrou m1 obtenu." << std::endl;

    NkChrono::SleepMilliseconds(100);

    nkentseu::threading::NkScopedLock<NkMutex> verrou2(m2);

    std::cout << "Fil a : verrou m2 obtenu." << std::endl;
}

void FonctionB(NkMutex& m1, NkMutex& m2)
{
    // Le fil b prend m1 en premier, comme le fil a.
    nkentseu::threading::NkScopedLock<NkMutex> verrou1(m1);

    std::cout << "Fil b : verrou m1 obtenu." << std::endl;

    // Conserver l'attente demandée par l'exercice.
    NkChrono::SleepMilliseconds(100);

    // Puis prendre m2.
    nkentseu::threading::NkScopedLock<NkMutex> verrou2(m2);

    std::cout << "Fil b : verrou m2 obtenu." << std::endl;
}

int main()
{
    // Les deux mutex partagés par les fils.
    NkMutex m1;
    NkMutex m2;

    std::cout << "Demarrage des deux fils..." << std::endl;

    // Création du premier fil : son paramètre est de type void*.
    NkThread a([&](void*)
    {
        FonctionA(m1, m2);
    });

    // Création du deuxième fil.
    NkThread b([&](void*)
    {
        FonctionB(m1, m2);
    });

    // Attendre la fin des deux fils.
    a.Join();
    b.Join();

    std::cout << "Les deux fils ont termine." << std::endl;

    return 0;
}

