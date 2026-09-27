#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>
#include <string>

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.width = 800;
    cfg.height = 600;

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

    std::string document = "MonDocument";
    bool modified = true;

    auto updateTitle = [&]()
    {
        auto windowSize = window.GetSize();

        auto width = windowSize.x;
        auto height = windowSize.y;

        std::string title = document;

        if (modified)
        {
            title += " *";
        }

        title += " - ";
        title += std::to_string(width);
        title += "x";
        title += std::to_string(height);

        window.SetTitle(title.c_str());
    };

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *)
        {
            running = false;
        }
    );

    updateTitle();

    auto lastSize = window.GetSize();

    while (running && window.IsOpen())
    {
        events.PollEvents();

        auto currentSize = window.GetSize();

        if (currentSize.x != lastSize.x ||
            currentSize.y != lastSize.y)
        {
            lastSize = currentSize;
            updateTitle();
        }
    }

    window.Close();

    return 0;
}