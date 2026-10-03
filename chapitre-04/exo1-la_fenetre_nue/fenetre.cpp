#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;
class Fenetre : public renderer::NkCanvasApp
{
public:
    Fenetre()
    {
        Config().title = "Ma fenetre";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = renderer::NkColor2D{67, 168, 240, 255};
    }
};

int nkmain(const NkEntryState &state)
{
    return renderer::NkCanvasApp::Run<Fenetre>(state);
}