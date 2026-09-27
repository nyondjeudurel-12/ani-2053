#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;

    cfg.title = "fenetre";

    // Les 7 propriétés testées
    cfg.resizable = false;
    cfg.movable = false;
    cfg.closable = false;
    cfg.minimizable = false;
    cfg.maximizable = false;
    cfg.canFullscreen = false;
    cfg.modal = true;

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

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}