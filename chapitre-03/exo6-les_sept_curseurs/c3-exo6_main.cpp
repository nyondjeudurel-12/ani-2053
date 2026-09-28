#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindow.h"
#include "NKWindow/Core/NkWindowConfig.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    (void)state;

    NkWindowConfig cfg;
    cfg.title = "Ma fenetre";

    cfg.resizable = true;
    cfg.movable = true;
    cfg.closable = true;
    cfg.minimizable = true;
    cfg.maximizable = true;
    cfg.canFullscreen = true;
    cfg.modal = true;

    NkWindow window(cfg);

    if (!window.IsValid())
    {
        return 1;
    }

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *)
        {
            running = false;
        }
    );

    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e)
        {
            auto taille = window.GetSize();

            float W = (float)taille.x;
            float H = (float)taille.y;

            float x = (float)e->GetX();

            // ZONE 1
            if (x < W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::Arrow);
            }

            // ZONE 2
            else if (x < 2 * W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::TextInput);
            }

            // ZONE 3
            else if (x < 3 * W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::Hand);
            }

            // ZONE 4
            else if (x < 4 * W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::ResizeNS);
            }

            // ZONE 5
            else if (x < 5 * W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::ResizeWE);
            }

            // ZONE 6
            else if (x < 6 * W / 7)
            {
                window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
            }

            // ZONE 7
            else
            {
                window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
            }
        }
    );

    while (running && window.IsOpen())
    {
        events.PollEvents();
        NkClock::Sleep((int64)10);
    }

    window.Close();

    return 0;
}

