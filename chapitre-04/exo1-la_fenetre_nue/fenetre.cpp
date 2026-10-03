#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;
using renderer::NkCanvasApp;
using renderer::NkColor2D;

class Fenetre : public NkCanvasApp
{
public:
    Fenetre()
    {
        Config().title = "Ma fenetre";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = NkColor2D{67, 168, 240, 255};
    }
};

int nkmain(const NkEntryState &state)
{
    return NkCanvasApp::Run<Fenetre>(state);
}