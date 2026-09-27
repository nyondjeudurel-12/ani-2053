## EXERCICE 2:(LES SEPTS DROITS)

* L'objectif ici serra de tester les sept proprietes de configuration d'une fenetre avec :

```
frame
resizable
minimizable
movable
closable
maximizable
canFullscreen
```

* je vais donc modifier mon fichier `.cpp` permettant d'ouvrir une fenetre basique que vois ci :

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.minimizable = false;

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

* le `frame=false`.j'ajoute  `cfg.frame = false;`

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.frame = false;

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

Ici, l'utilisateur ne peut plus utiliser le cadre classique de la fenêtre fourni par le système.

* le `resizable=false`. je remplace `cfg.frame = false;` par `cfg.resizable = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.resizable = false;
```

Ici, l'utilisateur ne peut plus redimensionner la fenêtre en modifiant sa largeur ou sa hauteur avec la souris.

* le `minimizable=false`. je remplace `cfg.resizable = false;` par `cfg.minimizable = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.minimizable = false;
```

Ici, l'utilisateur ne peut plus minimiser la fenêtre à l'aide du bouton de réduction du système.

* le `movable=false`. je remplace `cfg.minimizable = false;` par `cfg.movable = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.movable = false;
```

Ici, l'utilisateur ne peut plus déplacer la fenêtre sur l'écran en utilisant sa barre de titre.

* le `closable=false`. je remplace `cfg.movable = false;` par `cfg.closable = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.closable = false;
```

Ici, l'utilisateur ne peut plus fermer la fenêtre à l'aide du bouton de fermeture fourni par le système.

* le `maximizable=false`. je remplace `cfg.closable = false;` par `cfg.maximizable = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.maximizable = false;
```

Ici, l'utilisateur ne peut plus maximiser la fenêtre à l'aide du bouton prévu par le système.

* le `canFullscreen=false`. je remplace `cfg.maximizable = false;` par `cfg.canFullscreen = false;`

```
NkWindowConfig cfg;
cfg.title = "fenetre";
cfg.canFullscreen = false;
```

Ici, l'utilisateur ne peut plus passer la fenêtre en mode plein écran.

* Tableau des observations

| Droit           | Effet attendu                                                        | Effet observé             |
| --------------- | -------------------------------------------------------------------- | ------------------------- |
| frame         | Le cadre de la fenêtre est désactivé.                                | Non probleme lier a NKWindow |
| resizable     | L'utilisateur ne peut plus redimensionner la fenêtre.                | Non probleme lier a NKWindow |
| minimizable   | L'utilisateur ne peut plus minimiser la fenêtre.                     | Non probleme lier a NKWindow |
| movable       | L'utilisateur ne peut plus déplacer la fenêtre.                      | Non probleme lier a NKWindow |
| closable      | L'utilisateur ne peut plus fermer la fenêtre avec le bouton système. | Non probleme lier a NKWindow |
| maximizable   | L'utilisateur ne peut plus maximiser la fenêtre.                     | Non probleme lier a NKWindow |
| canFullscreen | L'utilisateur ne peut plus passer la fenêtre en plein écran.         | Non probleme lier a NKWindow |

* Vérification du backend

Pour chaque différence entre l'effet attendu et l'effet observé, je vais rechercher dans le backend du moteur si le droit concerné est réellement utilisé.

Si un droit n'est lu par aucun code du backend, cela explique pourquoi le comportement attendu n'est pas obtenu.

**Droit concerné :** à compléter après observation.

**Ligne du backend :** à compléter avec la ligne trouvée dans le moteur.

**Explication :** à compléter selon le comportement du backend.

* Conclusion:
***

Cet exercice permet de comparer l'effet attendu des sept droits de `NkWindowConfig` avec leur effet réellement observé. Lorsqu'il existe une différence, la lecture du backend permet de comprendre si le droit est réellement pris en compte par le moteur.
