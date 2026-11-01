#include "NKCanvas/App/NkCanvasApp.h"
#include "NKEvent/NkEventDispatcher.h"
#include "NKWindow/NKMain.h"

#include <fstream>

namespace nkentseu {

// VERSION DIRECTE : consulte directement le singleton NkInput.
bool PeutSauterDirectement(bool auSol) {
    return auSol && NkInput.IsKeyDown(NkKey::NK_SPACE);
}

// VERSION TESTABLE : reçoit les deux informations nécessaires.
bool PeutSauter(bool auSol, bool espaceEnfoncee) {
    return auSol && espaceEnfoncee;
}

class ApplicationBanc final : public renderer::NkCanvasApp {
protected:

    // Cette méthode est appelée avant la création de la fenêtre.
    NkOptional<int> OnCommandLine(
        const NkVector<NkString>& args) override {

        (void)args;

        std::ofstream journal("banc_resultats.txt");

        if (!journal.is_open()) {
            return NkOptional<int>(1);
        }

        // --------------------------------------------------
        // 1. Tester la version directe.
        // --------------------------------------------------
        journal << "Tester la version directe :\n";

        bool resultatDirect = PeutSauterDirectement(true);

        journal
            << "Personnage au sol, Espace demandee : "
            << (resultatDirect ? "true" : "false")
            << "\n";

        // --------------------------------------------------
        // 2. Présenter la version testable.
        // --------------------------------------------------
        journal << "\nLa version testable :\n";

        journal
            << "La fonction PeutSauter recoit deux booleens : "
            << "auSol et espaceEnfoncee.\n";

        journal
            << "Elle ne depend pas du singleton NkInput.\n";

        // --------------------------------------------------
        // 3. Exécuter les quatre tests.
        // --------------------------------------------------
        journal << "\nLe banc :\n";

        struct CasTest {
            bool auSol;
            bool espace;
            bool attendu;
        };

        // Les quatre situations possibles.
        CasTest tests[] = {
            {true,  true,  true},
            {true,  false, false},
            {false, true,  false},
            {false, false, false}
        };

        int echecs = 0;

        for (int i = 0; i < 4; ++i) {

            // Exécute la fonction avec les valeurs du test.
            bool obtenu = PeutSauter(
                tests[i].auSol,
                tests[i].espace
            );

            bool reussi = obtenu == tests[i].attendu;

            if (!reussi) {
                ++echecs;
            }

            journal
                << "Test " << (i + 1)
                << " : auSol=" << tests[i].auSol
                << ", espace=" << tests[i].espace
                << ", attendu=" << tests[i].attendu
                << ", obtenu=" << obtenu
                << " : "
                << (reussi ? "REUSSI" : "ECHEC")
                << "\n";
        }

        journal << "Nombre d'echecs : " << echecs << "\n";
        journal << "Code de sortie : " << echecs << "\n";

        // --------------------------------------------------
        // 4. Expliquer le test sans fenêtre.
        // --------------------------------------------------
        journal << "\nSans fenêtre :\n";

        journal
            << "La version directe retourne "
            << (resultatDirect ? "true" : "false")
            << ".\n";

        journal
            << "OnCommandLine est execute avant la creation "
            << "de la fenetre. Aucun appui sur Espace n'a "
            << "ete simule. La fonction depend donc de "
            << "l'etat reel fourni par NkInput.\n";

        journal.flush();

        // Le code de sortie correspond au nombre d'échecs.
        return NkOptional<int>(echecs);
    }
};

} // namespace nkentseu

// Point d'entrée de l'application.
// Point d'entrée de l'application.
int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<
        nkentseu::ApplicationBanc
    >(state);
}