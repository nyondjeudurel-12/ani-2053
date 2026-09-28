# Exercice 6: (Les septs curseurs)

* Pour faire cet exercice, mon travail a reposé sur des recherches dans les fichiers de Nkentseu et j'ai utiliser se programme:
```
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


```

* J'ai d'abord cherché comment gérer les différents types de curseurs. Je suis allé dans les fichiers de NKWindow et j'ai trouvé l'énumération NkCursorType.

enum class NkCursorType {

    Arrow = 0,
    TextInput,
    Hand,
    ResizeNS,
    ResizeWE,
    ResizeNWSE,
    ResizeNESW
};
Cette énumération m'a permis de connaître les sept types de curseurs disponibles et de les associer aux sept zones de ma fenêtre.

* DECOUPAGE DE LA FENETRE
Pour faire les sept zones, j'ai choisi de diviser la largeur de ma fenêtre en sept parties.


Chaque zone prend donc environ un septième de la largeur de la fenêtre et toute sa hauteur.
Le découpage est donc :

```
┌────┬────┬────┬────┬────┬────┬────┐
│ Z1 │ Z2 │ Z3 │ Z4 │ Z5 │ Z6 │ Z7 │
│    │    │    │    │    │    │    │
│    │    │    │    │    │    │    │
└────┴────┴────┴────┴────┴────┴────┘
```
* Test 1:
Dans le premier test, j'ai utilisé NkMouseMoveEvent pour détecter le déplacement de la souris.
J'ai récupéré la taille de la fenêtre avec :

```
auto taille = window.GetSize();

float W = (float)taille.x;
float H = (float)taille.y;
```
* Puis j'ai récupéré la position horizontale de la souris avec :

```
float x = (float)e->GetX();
```
* Ensuite, j'ai comparé la position x avec les limites des sept zones.
Pour chaque zone, j'ai utilisé une forme différente avec SetCursor().

```
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
```
Le changement du curseur est effectué à chaque NkMouseMoveEvent`.

* DESCRIPTION DE CE QUI SE PASSE AU SURVOL

Lorsque je déplace la souris dans les différentes zones, le curseur change en fonction de la zone dans laquelle il se trouve.

* ZONE 1
Le curseur prend la forme d'une flèche normale.
```
NkWindow::NkCursorType::Arrow
```

* ZONE 2
Le curseur prend la forme utilisée pour la saisie de texte.
```
NkWindow::NkCursorType::TextInput
```

* ZONE 3
Le curseur prend la forme d'une main.
```
NkWindow::NkCursorType::Hand
```

* ZONE 4
Le curseur indique un redimensionnement vertical :
```
↕
```

```
NkWindow::NkCursorType::ResizeNS
```

* ZONE 5
Le curseur indique un redimensionnement horizontal :
```
↔
```

```
NkWindow::NkCursorType::ResizeWE
```

* ZONE 6
Le curseur indique un redimensionnement diagonal :
```
↘↖
```

```
NkWindow::NkCursorType::ResizeNWSE
```

* ZONE 7
Le curseur indique un redimensionnement diagonal dans l'autre direction :
```
↗↙
```

```
NkWindow::NkCursorType::ResizeNESW
```
* RESULTAT DU BUILD:
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
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MY_WORKSPACE\MY_WORKSPACE.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.18s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

* RESULTAT OBSERVE:

| Zone   | Forme demandée | Forme obtenue |
| ------ | -------------- | ------------- |
| Zone 1 | Arrow          | Arrow         |
| Zone 2 | TextInput      | TextInput     |
| Zone 3 | Hand           | Hand          |
| Zone 4 | ResizeNS       | ResizeNS      |
| Zone 5 | ResizeWE       | ResizeWE      |
| Zone 6 | ResizeNWSE     | ResizeNWSE    |
| Zone 7 | ResizeNESW     | ResizeNESW    |

Dans mon test, les sept formes demandées changent bien lorsque je déplace la souris d'une zone à une autre.
* TEST 2
Pour le deuxième test, j'ai supprimé les appels à SetCursor() dans NkMouseMoveEvent.
J'ai gardé un seul appel au démarrage :

```
window.SetCursor(NkWindow::NkCursorType::Hand);
```
Le programme démarre donc avec le curseur Hand.
Lorsque je déplace ensuite la souris dans les différentes zones, aucun autre appel à SetCursor() n'est effectué.

* DESCRIPTION DE CE QUI SE PASSE AU SURVOL:
Lorsque je déplace la souris dans les différentes zones de la fenêtre, le curseur reste inchangé.
Il conserve la forme Hand pendant tout le déplacement.

Cela montre que le changement de zone ne change pas automatiquement la forme du curseur. C'est le programme qui doit appeler SetCursor() lorsqu'il détecte que la souris se trouve dans une autre zone.

* CONCLUSION
***

Cet exercice m'a permis de comprendre comment créer plusieurs zones dans une seule fenêtre et comment changer le curseur en fonction de la position de la souris.
J'ai aussi compris que NKWindow ne crée pas automatiquement les sept zones. C'est mon programme qui définit leurs limites et qui vérifie la position de la souris avec NkMouseMoveEvent.
Dans le deuxième test, j'ai constaté que si SetCursor() est appelé une seule fois au démarrage, le curseur garde la même forme même lorsque la souris passe d'une zone à une autre.
