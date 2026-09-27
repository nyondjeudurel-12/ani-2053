#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    
    NkWindow window(cfg);

    if (!window.IsOpen())
    {
        logger.Error("[app] creation fenetre echouer!!");
        return -1;
    }
    else
    {
        std::cout << "La fenetre est ouverte!!";
    }

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *)
        {
            running = false;
        }
    );
    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();
    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

    std::cout<<"Fenetre : "<< width << " X " <<height <<" | Surface : "<< surface.width << " X " <<surface.height<< " | Facteur d'echelle (DPI) : "<< window.GetDpiScale() << std::endl;

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}