#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

class Fenetre : public NkCanvasApp
{
public:
    Fenetre()
    {
        Config().title = "Carre rouge";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = NkColor2D{18, 18, 24, 255};
    }

    float x = 100.0f;
    float y = 100.0f;
    float vitesse = 100.0f;

    void OnUpdate(float dt) override
    {
        x += vitesse * dt;
    }

    void OnRender(NkRenderWindow& target) override
    {
        target.Clear(NkColor2D{18, 18, 24, 255});

        auto& renderer = target.GetRenderer2D();

        renderer.DrawFilledRect(
            {x, y, 50, 50},
            NkColor2D{255, 0, 0, 255}
        );
    }
};

int nkmain(const NkEntryState& state)
{
    return NkCanvasApp::Run<Fenetre>(state);
}