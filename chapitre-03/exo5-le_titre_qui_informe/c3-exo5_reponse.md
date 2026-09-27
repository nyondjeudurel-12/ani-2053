# EXERCICE 5: (Le titre qui informe)

* Pour cet exercice je vais utliser mon  progamme de base :
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

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
```
* j'ajoute ensuite ces elements suivants:
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>
#include <string>

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;

    // Nom du document + état modifié + taille
    cfg.title = "MonDocument * - 800x600";

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
```

j'ai affiche dans le titre de la fenêtre le nom du document, un asterisque indiquant que le document est modifier et les dimensions de la fenetre. La taille utilisee dans le titre correspond aux dimensions configurees lors de la creation de la fenetre.