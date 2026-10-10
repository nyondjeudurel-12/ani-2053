#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKTime/NkTime.h"

using namespace nkentseu;
using namespace nkentseu::renderer;

int nkmain(const NkEntryState& state)
{
    NkWindowConfig config{};
    config.title = "Carre rouge";
    config.width = 800;
    config.height = 600;

    float x = 100.0f;
    float y = 100.0f;

    NkWindow window;

    if(!window.Create(config)){
        logger.Error("Failed to create window");
        return 1;
    }

    if(!window.IsOpen()){
        logger.Error("Window is not open");
        return 1;
    }

    NkContextDesc contextDesc;
    contextDesc.api = NkGraphicsApi::NK_GFX_API_OPENGL;

    NkRenderWindow renderwindow(window, contextDesc);

    if(!renderwindow.IsValid()){
        logger.Error("Failed to initialize render window");
        return 2;
    }
    bool running = true;
    auto& eventSystem = NkEvents();
    NkClock clock;

    while(running && window.IsOpen())
    {
        // Temps
        float32 dt = clock.Tick().delta;

        if(dt > 0.1f)
            dt = 1.0f / 60.0f;

        // Événements
        NkEvent* event;
        while(eventSystem.PollEvent(event)){
            if(event->Is<NkWindowCloseEvent>()){
                running = false;
            }
        }

        // Mise à jour
        x += 100.0f * dt;

        // Effacer l'écran
        renderwindow.Clear(NkColor2D{18, 18, 24, 255});

        // Dessiner le carré rouge
        auto& Rectangle = renderwindow.GetRenderer2D();

        Rectangle.DrawFilledRect(
            {x, y, 50, 50},
            NkColor2D{255, 0, 0, 255}
        );
        // Afficher
        renderwindow.Display();
    }
    return 0;
}