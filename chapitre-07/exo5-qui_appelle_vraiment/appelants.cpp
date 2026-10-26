#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Core/NkDrawable.h"
#include "NKCanvas/Renderer/Core/NkRenderer2DTypes.h"
#include "NKCanvas/Renderer/Targets/NkRenderTarget.h"
#include "NKWindow/Core/NkEntry.h"

namespace nkentseu {

// Objet personnalisé qui sait dessiner ses propres sommets.
class MonObjet final : public renderer::NkDrawable {
public:

    // Redéfinition de Draw : c'est ici que nous allons observer les appels.
    void Draw(
        renderer::NkRenderTarget& target,
        const renderer::NkRenderStates& states
    ) const override {

        // POINT D'ARRÊT :
        // Dans VS Code, clique dans la marge à gauche de la ligne suivante.
        // Un cercle rouge doit apparaître.
        const renderer::NkVertex sommets[4] = {
            {100.0f, 100.0f, 0.0f, 0.0f, 255,   0,   0, 255},
            {300.0f, 100.0f, 0.0f, 0.0f, 255,   0,   0, 255},
            {200.0f, 150.0f, 0.0f, 0.0f,   0, 255,   0, 255},
            {200.0f, 300.0f, 0.0f, 0.0f,   0, 255,   0, 255}
        };

        // Transmet les quatre sommets au moteur graphique.
        target.Draw(
            sommets,
            4,
            renderer::NkPrimitiveType::NK_LINES,
            states
        );
    }
};

// Application qui affiche notre objet.
class ApplicationAppelants final : public renderer::NkCanvasApp {
public:
    ApplicationAppelants() {
        // Configure la fenêtre.
        Config().title = "Qui appelle vraiment ?";
        Config().width = 640;
        Config().height = 480;
        Config().clearColor = {18, 18, 24, 255};
    }

protected:
    // Cette méthode est appelée pendant le rendu de l'application.
    void OnRender(renderer::NkRenderWindow& target) override {

        // Efface l'image précédente.
        target.Clear(Config().clearColor);

        // Crée l'objet à dessiner.
        const MonObjet objet;

        // Demande au moteur de dessiner l'objet.
        // C'est cet appel qui conduit à MonObjet::Draw().
        target.Draw(objet);
    }
};

} // namespace nkentseu

// Point d'entrée de l'application.
int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::
        Run<nkentseu::ApplicationAppelants>(state);
}
