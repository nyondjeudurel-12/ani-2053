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
        std::cout << "La fenetre est ouverte!!" << std::endl;
    }

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *)
        {
            running = false;
        }
    );

    // Affichage des mouvements de la souris
    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e)
        {
            std::cout << "Souris : "
                      << e->GetX()
                      << " ; "
                      << e->GetY()
                      << std::endl;
        }
    );

    // Activation de la capture avec le clic gauche
    events.AddEventCallback<NkMouseButtonPressEvent>(
        [&](NkMouseButtonPressEvent *e)
        {
            if (e->IsLeft())
            {
                std::cout << "Clic gauche : capture active"
                          << std::endl;

                window.CaptureMouse(true);
            }
        }
    );

    // Liberation de la capture avec le relachement du clic gauche
    events.AddEventCallback<NkMouseButtonReleaseEvent>(
        [&](NkMouseButtonReleaseEvent *e)
        {
            if (e->IsLeft())
            {
                std::cout << "Clic gauche : capture liberee"
                          << std::endl;

                window.CaptureMouse(false);
            }
        }
    );

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}