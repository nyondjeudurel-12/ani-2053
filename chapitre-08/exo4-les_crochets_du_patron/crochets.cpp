#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"

#include <fstream>

namespace nkentseu {

class ApplicationCrochets final : public renderer::NkCanvasApp {
private:
    // Fichier qui conserve les appels des crochets.
    std::ofstream journal{"crochets_journal.txt", std::ios::out};

    // Compteurs pour suivre les appels et les images.
    unsigned int sequence = 0;
    unsigned int image = 0;

    // Évite de remplir le journal à chaque image.
    bool updateJournalise = false;
    bool renderJournalise = false;
    bool renderFinalJournalise = false;

    // Évite de journaliser plusieurs fois les événements.
    bool eventJournalise = false;
    bool pointerJournalise = false;
    bool keyJournalise = false;
    bool pauseJournalisee = false;
    bool resumeJournalisee = false;

    // Enregistre un appel avec son numéro, son image et le temps.
    void Journaliser(const char* nom) {
        if (journal.is_open()) {
            journal
                << ++sequence
                << " | " << nom
                << " | Image : " << image
                << " | Time : " << Time() << " s\n";

            journal.flush();
        }
    }

public:
    ApplicationCrochets() {
        // Configure la fenêtre de test.
        Config().title = "Les crochets du patron";
        Config().width = 640;
        Config().height = 480;
        Config().imagesParSeconde = 30;
        Config().clearColor = {18, 18, 24, 255};
    }

protected:
    // 1. Appelé avant la création de la fenêtre.
    NkOptional<int> OnCommandLine(
        const NkVector<NkString>& args) override {

        (void)args;
        Journaliser("OnCommandLine");
        return NkOptional<int>();
    }

    // 2. Initialisation de l'application.
    bool OnInit() override {
        Journaliser("OnInit");
        return true;
    }

    // 3. Mise à jour de l'application.
    void OnUpdate(float32 deltaTime) override {
        (void)deltaTime;

        ++image;

        // On journalise seulement la première et la dernière mise à jour.
        if (!updateJournalise || image == 5) {
            Journaliser("OnUpdate");
            updateJournalise = true;
        }
    }

    // 4. Affichage de l'image.
    void OnRender(renderer::NkRenderWindow& target) override {
        target.Clear(Config().clearColor);

        // On journalise le premier et le dernier rendu.
        if (!renderJournalise || (image >= 5 && !renderFinalJournalise)) {
            Journaliser("OnRender");
            renderJournalise = true;

            if (image >= 5) {
                renderFinalJournalise = true;
            }
        }

        // Arrêt automatique après cinq images.
        if (image >= 5) {
            Quit();
        }
    }

    // 5. Arrêt de l'application.
    void OnShutdown() override {
        Journaliser("OnShutdown");

        if (journal.is_open()) {
            journal.close();
        }
    }

    // 6. Réception d'un événement brut.
    bool OnEvent(const NkEvent& event) override {
        (void)event;

        if (!eventJournalise) {
            Journaliser("OnEvent");
            eventJournalise = true;
        }

        return false;
    }

    // 7. Réception d'un événement souris ou tactile.
    bool OnPointer(const NkPointer& pointer) override {
        (void)pointer;

        if (!pointerJournalise) {
            Journaliser("OnPointer");
            pointerJournalise = true;
        }

        return false;
    }

    // 8. Réception d'une touche du clavier.
    bool OnKeyPress(const NkKeyPressEvent& event) override {
        (void)event;

        if (!keyJournalise) {
            Journaliser("OnKeyPress");
            keyJournalise = true;
        }

        return false;
    }



    // 10. Demande de fermeture de la fenêtre.
    bool OnCloseRequested() override {
        Journaliser("OnCloseRequested");
        return true;
    }

    // 11. Mise en arrière-plan.
    void OnPause() override {
        if (!pauseJournalisee) {
            Journaliser("OnPause");
            pauseJournalisee = true;
        }
    }

    // 12. Retour au premier plan.
    void OnResume() override {
        if (!resumeJournalisee) {
            Journaliser("OnResume");
            resumeJournalisee = true;
        }
    }
};

} // namespace nkentseu

// Point d'entrée du programme.
int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::
        Run<nkentseu::ApplicationCrochets>(state);
}