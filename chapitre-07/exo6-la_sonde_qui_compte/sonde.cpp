#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"
#include <fstream>
#include <iostream>

namespace nkentseu {
// Désactive le plafond de cadence pour ce test.
constexpr int CADENCE_VISEE = 60;

// Conserve la journalisation pour mesurer son coût.
constexpr bool JOURNAL_ACTIF = true;

class ApplicationSonde final : public renderer::NkCanvasApp {
private:
    // Nombre de passages dans OnRender().
    unsigned long long compteur = 0;

    // Empêche d'écrire plusieurs fois le résultat final.
    bool resultatEnregistre = false;

public:
    ApplicationSonde() {
        // Configure la fenêtre et la cadence visée.
        Config().title = "La sonde qui compte";
        Config().width = 640;
        Config().height = 480;
        Config().imagesParSeconde = CADENCE_VISEE;
        Config().clearColor = {18, 18, 24, 255};
    }

protected:
    void OnRender(renderer::NkRenderWindow& target) override {
        // Compte chaque passage dans la boucle de rendu.
        ++compteur;

        // Récupère le temps écoulé depuis OnInit().
        const auto temps = Time();

        // SONDE : cette ligne peut modifier la cadence mesurée.
        if (JOURNAL_ACTIF) {
            std::cout
                << "[SONDE] Passage = " << compteur
                << " | Time = " << temps << " s"
                << std::endl;
        }

        // Affiche une couleur de fond pour conserver une fenêtre visible.
        target.Clear(Config().clearColor);

        // Arrête la mesure après dix secondes.
        if (temps >= 10.0 && !resultatEnregistre) {
            resultatEnregistre = true;

            // Enregistre les résultats dans un fichier.
            std::ofstream fichier("sonde_mesures.txt", std::ios::app);

            if (fichier.is_open()) {
                fichier
                    << "Cadence visee : " << CADENCE_VISEE << '\n'
                    << "Journal actif : "
                    << (JOURNAL_ACTIF ? "oui" : "non") << '\n'
                    << "Nombre de passages : " << compteur << '\n'
                    << "Temps final : " << temps << " s\n"
                    << "------------------------------\n";

                fichier.close();
            }

            // Affiche aussi le bilan final dans le terminal.
            std::cout
                << "\n[BILAN] Cadence visee = " << CADENCE_VISEE
                << " | Journal actif = "
                << (JOURNAL_ACTIF ? "oui" : "non")
                << " | Passages = " << compteur
                << " | Temps = " << temps << " s"
                << std::endl;

            // Demande l'arrêt de l'application.
            Quit();
        }
    }
};

} // namespace nkentseu


// Point d'entrée utilisé par le moteur NKentseu.
int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::
        Run<nkentseu::ApplicationSonde>(state);
}

