# EXERCICE 5:(L'ETAT DU PROGRAMME DANS LE TITRE)

* L'objectif ici est d'afficher dans le titre de la fenetre l'etat de mon programme. Le titre doit contenir le nom du document, un asterisque  lorsque le document est modifie, ainsi que la taille actuelle de la fenetre.

* le programme que j'ai utiliser est le suivant :
```
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

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}#include "NKWindow/NKWindow.h"
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

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}
```

* Pour commencer, j'ai cree une fenetre avec une taille de 800 x 600 :

```
cfg.title = "fenetre";
cfg.width = 800;
cfg.height = 600;
```

* Ensuite, j'ai cree les variables permettant de representer le document et son etat :

```
std::string document = "MonDocument";
bool modified = true;
```

La variable document contient le nom du document et modified permet de savoir si le document a ete modifie.

*  J'ai ensuite recupere la taille actuelle de la fenetre avec :

```
auto windowSize = window.GetSize();

auto width = windowSize.x;
auto height = windowSize.y;
```

Ces valeurs me permettent de connaitre la largeur et la hauteur actuelles de la fenetre.

* J ai construit ensuite le titre avec le nom du document, l'asterisque si le document est modifie et la taille de la fenetre :

```
std::string title = document;

if (modified)
{
    title += " *";
}

title += " - ";
title += std::to_string(width);
title += "x";
title += std::to_string(height);
```

Le titre obtenu est donc par exemple :

```
MonDocument * - 800x600
```

* J'ai ensuite utilise une fonction updateTitle() pour regrouper les instructions permettant de mettre a jour le titre.

Enfin, j'ai compare la taille actuelle de la fenetre avec la taille precedente :

```
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
```

* maintenant , le titre n'est pas modifie a chaque image. Il est mis à jour uniquement lorsque la taille de la fenetre change.
 resultat:

Au lancement du programme, le titre affiche par exemple :

```
MonDocument * - 800x600
```

* Lorsque je redimensionne la fenetre, la taille affiche dans le titre change egalement.
Par exemple, si je redimensionne la fenetre en 1000 x 700, le titre devient :

```
MonDocument * - 1000x700
```

L'asterisque permet de signaler que le document est modifie.

*  Conclusion:
***

Cet exercice m'a permis de comprendre comment utiliser les informations de la fenêtre pour afficher son état directement dans le titre. J'ai également compris qu'il est préférable de mettre à jour le titre seulement lorsqu'une information change, plutôt que de le modifier à chaque image.
