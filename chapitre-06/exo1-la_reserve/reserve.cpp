#include <NKThreading/NkThread.h>
#include <NKThreading/NkThreadPool.h>
#include <NKTime/NkChrono.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace nkentseu;
using namespace nkentseu::threading;

constexpr int NOMBRE_TACHES = 200;
constexpr int NOMBRE_ESSAIS = 3;
constexpr int NOMBRE_OUVRIERS = 4;

// Effectue un calcul dont la durée dépend du nombre de répétitions.
long long CalculerSomme(int repetitions)
{
    volatile long long somme = 0;

    for (int repetition = 0; repetition < repetitions; ++repetition)
    {
        for (int i = 0; i <= 1000; ++i)
        {
            somme += i;
        }
    }

    return somme;
}

// Exécute 200 tâches avec la réserve et renvoie le temps mesuré.
double MesurerReserve(
    NkThreadPool& reserve,
    std::vector<long long>& resultats,
    int repetitions)
{
    NkChrono chrono;

    for (int i = 0; i < NOMBRE_TACHES; ++i)
    {
        reserve.Enqueue([i, &resultats, repetitions]()
        {
            resultats[i] = CalculerSomme(repetitions);
        });
    }

    reserve.Join();

    return chrono.Elapsed().ToMilliseconds();
}

// Exécute 200 tâches en créant 200 fils indépendants.
double MesurerFils(
    std::vector<long long>& resultats,
    int repetitions)
{
    std::vector<NkThread> fils;
    fils.reserve(NOMBRE_TACHES);

    NkChrono chrono;

    for (int i = 0; i < NOMBRE_TACHES; ++i)
    {
        fils.emplace_back([i, &resultats, repetitions](void*)
        {
            resultats[i] = CalculerSomme(repetitions);
        });
    }

    for (auto& fil : fils)
    {
        fil.Join();
    }

    return chrono.Elapsed().ToMilliseconds();
}

// Affiche les résultats des trois essais et leur moyenne.
void AfficherMesures(
    const char* nom,
    const std::vector<double>& mesures)
{
    double total = 0.0;

    std::cout << nom << '\n';

    for (std::size_t i = 0; i < mesures.size(); ++i)
    {
        std::cout << "  Essai " << i + 1
                  << " : " << mesures[i] << " ms\n";

        total += mesures[i];
    }

    double moyenne = total / mesures.size();

    std::cout << "  Moyenne : " << moyenne << " ms\n\n";
}

// Écrit les trois mesures et leur moyenne dans le fichier.
void EcrireMesures(
    std::ofstream& fichier,
    const char* nom,
    const std::vector<double>& mesures)
{
    double total = 0.0;

    fichier << nom << ' ';

    for (double temps : mesures)
    {
        fichier << temps << " ms ; ";
        total += temps;
    }

    fichier << "Moyenne : "
            << total / mesures.size()
            << " ms\n";
}

// Vérifie les résultats calculés.
long long VerifierResultats(const std::vector<long long>& resultats)
{
    long long total = 0;

    for (long long resultat : resultats)
    {
        total += resultat;
    }

    return total;
}

int main()
{
    std::cout << std::fixed << std::setprecision(3);

    NkThreadPool reserve(NOMBRE_OUVRIERS);

    std::vector<long long> resultats(NOMBRE_TACHES, 0);

    std::vector<double> mesuresReserve;
    std::vector<double> mesuresFils;
    std::vector<double> mesuresReserveLongue;
    std::vector<double> mesuresFilsLongs;

    mesuresReserve.reserve(NOMBRE_ESSAIS);
    mesuresFils.reserve(NOMBRE_ESSAIS);
    mesuresReserveLongue.reserve(NOMBRE_ESSAIS);
    mesuresFilsLongs.reserve(NOMBRE_ESSAIS);

    std::cout << "========================================\n";
    std::cout << "       EXERCICE : LA RESERVE\n";
    std::cout << "========================================\n\n";

    std::cout << "Nombre de tâches : "
              << NOMBRE_TACHES << '\n';

    std::cout << "Nombre d'ouvriers : "
              << reserve.GetNumWorkers() << "\n\n";

    // PREMIERE EXPERIENCE : TACHES COURTES

    constexpr int REPETITIONS_COURTES = 100;

    std::cout << "===== TACHES COURTES =====\n\n";

    for (int essai = 0; essai < NOMBRE_ESSAIS; ++essai)
    {
        double tempsReserve = MesurerReserve(
            reserve, resultats, REPETITIONS_COURTES);

        std::cout << "Vérification réserve : "
                  << VerifierResultats(resultats) << '\n';

        mesuresReserve.push_back(tempsReserve);

        double tempsFils = MesurerFils(
            resultats, REPETITIONS_COURTES);

        std::cout << "Vérification fils : "
                  << VerifierResultats(resultats) << '\n';

        mesuresFils.push_back(tempsFils);
    }

    AfficherMesures("Réserve :", mesuresReserve);
    AfficherMesures("Fils individuels :", mesuresFils);

    // DEUXIEME EXPERIENCE : TACHES 100 FOIS PLUS LONGUES
    
    constexpr int REPETITIONS_LONGUES = REPETITIONS_COURTES * 100;

    std::cout << "===== TACHES LONGUES =====\n\n";

    for (int essai = 0; essai < NOMBRE_ESSAIS; ++essai)
    {
        double tempsReserve = MesurerReserve(
            reserve, resultats, REPETITIONS_LONGUES);

        std::cout << "Vérification réserve longue : "
                  << VerifierResultats(resultats) << '\n';

        mesuresReserveLongue.push_back(tempsReserve);

        double tempsFils = MesurerFils(
            resultats, REPETITIONS_LONGUES);

        std::cout << "Vérification fils longs : "
                  << VerifierResultats(resultats) << '\n';

        mesuresFilsLongs.push_back(tempsFils);
    }

    AfficherMesures("Réserve avec tâches longues :", mesuresReserveLongue);
    AfficherMesures("Fils avec tâches longues :", mesuresFilsLongs);

    // ENREGISTREMENT DANS reserve.txt
   
    std::ofstream fichier("reserve.txt");

    if (!fichier)
    {
        std::cerr << "Erreur : impossible de créer reserve.txt.\n";
        reserve.Shutdown();
        return 1;
    }

    fichier << std::fixed << std::setprecision(3);

    fichier << "Tâche : " << NOMBRE_TACHES
            << " tâches indépendantes par essai.\n";

    EcrireMesures(fichier, "Réserve :", mesuresReserve);
    EcrireMesures(fichier, "Fils :", mesuresFils);

    fichier << "Ouvriers : "
            << reserve.GetNumWorkers() << '\n';

    fichier << "Tâche longue : chaque tâche effectue "
            << REPETITIONS_LONGUES
            << " répétitions, contre "
            << REPETITIONS_COURTES
            << " pour une tâche courte.\n";

    EcrireMesures(
        fichier, "Réserve longue :", mesuresReserveLongue);

    EcrireMesures(
        fichier, "Fils longs :", mesuresFilsLongs);

    fichier << "Pourquoi : la réserve réutilise un nombre limité "
            << "d'ouvriers pour traiter les tâches. Les fils "
            << "individuels nécessitent la création et la "
            << "synchronisation de nombreux fils. Ce coût peut "
            << "être important pour les tâches courtes. Lorsque "
            << "les tâches sont plus longues, le coût de création "
            << "des fils peut représenter une part moins importante "
            << "du temps total. Les résultats dépendent aussi du "
            << "processeur et du système d'exploitation.\n";

    fichier.close();

    reserve.Shutdown();

    std::cout << "\nLes résultats ont été enregistrés dans reserve.txt.\n";

    return 0;
}
