# EXERCICE 3:(Les Bornes)

* commecons par fixer une taille minimal pour cette exercice je vais continuer a travailler avec ce programme:
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.minWidth = 400;
    cfg.minHeight = 300;

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
j'ai fixer une taille minimal avec :
```
cfg.minWidth = 400;
cfg.minHeight = 300;
```
je constate donc que quand je redimensionne la fenetre elle ne peut pas aller en dessous de 400 px pour 300 px . elle bloque . lesysteme reconnais donc :
cfg.minWidth = 400;
cfg.minHeight = 300; comme la plus petite taille.

* je retire la taille minimimal donc mon NkWindowConfig cfg devient :
````
NkWindowConfig cfg;
cfg.title = "fenetre";
````
* je construit :
```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. MY_WORKSPACE [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MY_WORKSPACE                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo3_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MY_WORKSPACE\MY_WORKSPACE.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.53s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.53s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
et la je constate que quand je redimenssionne la fenetre elle bloque a la taille auquel l'icone de la fenetre et les 03 bouttons donc fermer agrandir et reduire son visible suivie d'un petit ecart pour montrer la fenetre sur la hauteur . je dirais environ 120px pour 80 px.

* Conclusion
****
Cette expérience m'a permis de comprendre le fonctionnement de minWidth et minHeight. Lorsque ces deux propriétés sont définies, elles empêchent la fenêtre de devenir plus petite que les dimensions indiquées. Après avoir retiré ces limites, j'ai pu observer la plus petite taille que le système accepte naturellement. Cela montre que la taille minimale d'une fenêtre peut être contrôlée par la configuration ou dépendre des limites appliquées par le système.


