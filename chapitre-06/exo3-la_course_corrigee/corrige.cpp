#include <NKThreading/NkThread.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKCore/NkAtomic.h>
#include <NKTime/NkChrono.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace nkentseu;
using namespace nkentseu::threading;

// Paramètres de l'expérience
constexpr int NOMBRE_FILS = 8;
constexpr int INCREMENTS_PAR_FIL = 1000000;
constexpr int NOMBRE_ESSAIS = 3;

using Temps = double;

// Résultat d'une exécution
struct Resultat
{
    long long total;
    Temps tempsMs;
};

// Calcule la médiane des temps mesurés
Temps Mediane(std::vector<Temps> temps)
{
    std::sort(temps.begin(), temps.end());
    return temps[temps.size() / 2];
}

// Affiche le résultat d'un essai
void AfficherEssai(
    const std::string& nom,
    int numero,
    const Resultat& resultat)
{
    std::cout << nom
              << " - Essai " << numero
              << " : Total = " << resultat.total
              << ", Temps = " << resultat.tempsMs
              << " ms" << std::endl;
}
// VERSION 1 : COMPTEUR PARTAGÉ SANS PROTECTION
Resultat SansProtection()
{
    long long compteur = 0;

    // Démarre le chronomètre
    NkChrono chrono;

    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_FILS);

    // Tous les fils modifient le même compteur
    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        fils.emplace_back([&compteur](void*)
        {
            for (int j = 0; j < INCREMENTS_PAR_FIL; ++j)
            {
                // Course de données : aucun verrouillage
                compteur += 1;
            }
        });
    }

    // Attend la fin de tous les fils
    for (auto& fil : fils)
    {
        fil.Join();
    }

    // Récupère le total et le temps écoulé
    Resultat resultat;
    resultat.total = compteur;
    resultat.tempsMs = chrono.Elapsed().ToMilliseconds();

    return resultat;
}

// ------------------------------------------------------------------
// VERSION 2 : COMPTEUR PROTÉGÉ PAR UN MUTEX
// ------------------------------------------------------------------
Resultat AvecMutex()
{
    long long compteur = 0;
    NkMutex mutex;

    // Démarre le chronomètre
    NkChrono chrono;

    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_FILS);

    // Chaque fil protège son incrément avec un mutex
    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        fils.emplace_back([&compteur, &mutex](void*)
        {
            for (int j = 0; j < INCREMENTS_PAR_FIL; ++j)
            {
                // Verrouille le mutex pendant la modification
                nkentseu::threading::NkScopedLock<NkMutex> verrou(mutex);
                compteur += 1;
            }
        });
    }

    // Attend la fin de tous les fils
    for (auto& fil : fils)
    {
        fil.Join();
    }

    // Récupère le total et le temps écoulé
    Resultat resultat;
    resultat.total = compteur;
    resultat.tempsMs = chrono.Elapsed().ToMilliseconds();

    return resultat;
}

// VERSION 3 : COMPTEUR ATOMIQUE

Resultat AvecAtomique()
{
    NkAtomicInt compteur(0);

    // Démarre le chronomètre
    NkChrono chrono;

    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_FILS);

    // Les fils utilisent une opération atomique pour incrémenter
    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        fils.emplace_back([&compteur](void*)
        {
            for (int j = 0; j < INCREMENTS_PAR_FIL; ++j)
            {
                compteur.FetchAdd(1);
            }
        });
    }

    // Attend la fin de tous les fils
    for (auto& fil : fils)
    {
        fil.Join();
    }

    // FetchAdd(0) récupère la valeur sans la modifier
    Resultat resultat;
    resultat.total = compteur.FetchAdd(0);
    resultat.tempsMs = chrono.Elapsed().ToMilliseconds();

    return resultat;
}
// VERSION 4 : COMPTEURS LOCAUX
Resultat AvecCompteursLocaux()
{
    // Chaque fil dispose de son propre emplacement de résultat
    std::vector<long long> resultats(NOMBRE_FILS, 0);

    // Démarre le chronomètre
    NkChrono chrono;

    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_FILS);

    // Chaque fil incrémente son propre compteur local
    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        fils.emplace_back([&resultats, i](void*)
        {
            long long compteurLocal = 0;

            for (int j = 0; j < INCREMENTS_PAR_FIL; ++j)
            {
                compteurLocal += 1;
            }

            // Chaque fil écrit dans un emplacement distinct
            resultats[i] = compteurLocal;
        });
    }

    // Attend la fin de tous les fils
    for (auto& fil : fils)
    {
        fil.Join();
    }

    // Additionne les résultats une fois tous les fils terminés
    long long total = 0;

    for (int i = 0; i < NOMBRE_FILS; ++i)
    {
        total += resultats[i];
    }

    // Récupère le total et le temps écoulé
    Resultat resultat;
    resultat.total = total;
    resultat.tempsMs = chrono.Elapsed().ToMilliseconds();

    return resultat;
}

// MESURE D'UNE VERSION SUR TROIS ESSAIS
std::vector<Resultat> MesurerVersion(
    const std::string& nom,
    Resultat (*fonction)())
{
    std::vector<Resultat> resultats;
    resultats.reserve(NOMBRE_ESSAIS);

    // Exécute la fonction plusieurs fois
    for (int i = 0; i < NOMBRE_ESSAIS; ++i)
    {
        Resultat resultat = fonction();
        resultats.push_back(resultat);

        AfficherEssai(nom, i + 1, resultat);
    }

    return resultats;
}

// Extrait les temps des résultats
std::vector<Temps> ExtraireTemps(
    const std::vector<Resultat>& resultats)
{
    std::vector<Temps> temps;
    temps.reserve(resultats.size());

    for (const auto& resultat : resultats)
    {
        temps.push_back(resultat.tempsMs);
    }

    return temps;
}

// Affiche le bilan d'une version
void AfficherBilan(
    const std::string& nom,
    const std::vector<Resultat>& resultats)
{
    // Calcule la médiane des trois mesures
    Temps mediane = Mediane(ExtraireTemps(resultats));

    std::cout << nom
              << " : Total du dernier essai = "
              << resultats.back().total
              << " ; médiane = "
              << mediane << " ms" << std::endl;
}
// PROGRAMME PRINCIPAL
int main()
{
    std::cout << "========================================" << std::endl;
    std::cout << " EXERCICE 3 - LA COURSE CORRIGEE" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Nombre de fils : " << NOMBRE_FILS << std::endl;
    std::cout << "Increments par fil : "
              << INCREMENTS_PAR_FIL << std::endl;
    std::cout << "Essais par version : "
              << NOMBRE_ESSAIS << std::endl;

    // Version 1 : sans protection
    std::cout << "\n--- Sans protection ---" << std::endl;
    auto sansProtection = MesurerVersion(
        "Sans protection", SansProtection);

    // Version 2 : avec mutex
    std::cout << "\n--- Avec mutex ---" << std::endl;
    auto avecMutex = MesurerVersion(
        "Mutex", AvecMutex);

    // Version 3 : avec compteur atomique
    std::cout << "\n--- Avec atomique ---" << std::endl;
    auto avecAtomique = MesurerVersion(
        "Atomique", AvecAtomique);

    // Version 4 : avec compteurs locaux
    std::cout << "\n--- Avec compteurs locaux ---" << std::endl;
    auto avecLocaux = MesurerVersion(
        "Local", AvecCompteursLocaux);

    // Calcule les quatre médianes
    Temps medianeSansProtection =
        Mediane(ExtraireTemps(sansProtection));

    Temps medianeMutex =
        Mediane(ExtraireTemps(avecMutex));

    Temps medianeAtomique =
        Mediane(ExtraireTemps(avecAtomique));

    Temps medianeLocaux =
        Mediane(ExtraireTemps(avecLocaux));

    // Recherche la version avec la médiane la plus faible
    std::string moinsChere = "Sans protection";
    Temps meilleureMediane = medianeSansProtection;

    if (medianeMutex < meilleureMediane)
    {
        meilleureMediane = medianeMutex;
        moinsChere = "Mutex";
    }

    if (medianeAtomique < meilleureMediane)
    {
        meilleureMediane = medianeAtomique;
        moinsChere = "Atomique";
    }

    if (medianeLocaux < meilleureMediane)
    {
        meilleureMediane = medianeLocaux;
        moinsChere = "Local";
    }

    // Affiche les bilans sans créer de fichier
    std::cout << "\n========================================" << std::endl;
    std::cout << " BILAN DES RESULTATS" << std::endl;
    std::cout << "========================================" << std::endl;

    AfficherBilan("Sans protection", sansProtection);
    AfficherBilan("Mutex", avecMutex);
    AfficherBilan("Atomique", avecAtomique);
    AfficherBilan("Local", avecLocaux);

    std::cout << "\nLa moins chere : "
              << moinsChere
              << " (mediane : "
              << meilleureMediane
              << " ms)" << std::endl;

    // Explique les différences observées
    std::cout << "\nPourquoi :" << std::endl;

    std::cout
        << "Sans protection : les fils modifient simultanement "
        << "le meme compteur. Cela provoque une course de donnees "
        << "et un comportement indefini." << std::endl;

    std::cout
        << "Mutex : chaque increment verrouille puis deverrouille "
        << "le mutex, ce qui ajoute un cout de synchronisation."
        << std::endl;

    std::cout
        << "Atomique : les operations atomiques protegent le compteur, "
        << "mais les fils se disputent toujours le meme emplacement "
        << "memoire." << std::endl;

    std::cout
        << "Local : chaque fil utilise son propre compteur, puis les "
        << "resultats sont additionnes apres la fin des fils. "
        << "Cela reduit la synchronisation pendant les increments."
        << std::endl;

    return 0;
}

