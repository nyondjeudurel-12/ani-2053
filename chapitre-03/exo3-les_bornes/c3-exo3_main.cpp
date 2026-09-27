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

     events.AddEventCallback<NkWindowResizeEvent>(
        [](NkWindowResizeEvent *e) {
            logger.Info("taille actuelle ->Taille : {} x {}", e->GetWidth(), e->GetHeight());
        }
    );

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}