# EXERCICE 4:( Le facteur d'echelle)

* Pour cette exercice je vais continuer a utiiser mon programme de base que voici :
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
    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();
    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

    std::cout<<"Fenetre : "<< width << " X " <<height <<" | Surface : "<< surface.width << " X " <<surface.height<< " | Facteur d'echelle (DPI) : "<< window.GetDpiScale() << std::endl;

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}
```

* Pour cet exercice je suis aller me ressourcer dans les fichiers NKWindow.h et dans NKSurface de Nkentseu pour recuperer toutes les variables :
```
auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();
    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

```
* ce sonrt donc ses variables qui vont me permettre d' Affichez côte à côte la taille rendue par la fenêtre , la taille rendue par la cible de rendu et le facteur d'echelle du systeme.

* je build donc mon nouveau .cpp:
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
    auto windowSize = window.GetSize();
    auto surface = window.GetSurfaceDesc();
    auto width = windowSize.x;
    auto height = windowSize.y;
    auto surfaceWidth = surface.width;
    auto surfaceHeight = surface.height;
    auto dpi = window.GetDpiScale();

    std::cout<<"Fenetre : "<< width << " X " <<height <<" | Surface : "<< surface.width << " X " <<surface.height<< " | Facteur d'echelle (DPI) : "<< window.GetDpiScale() << std::endl;

    while (running && window.IsOpen())
    {
        events.PollEvents();
    }

    window.Close();

    return 0;
}
```
resultat:

```
La fenetre est ouverte!!Fenetre : 1280 X 720 | Surface : 1280 X 720 | Facteur d'echelle (DPI) : 1
```
* maintenant changeons le reglage du systeme concernant l'echelle:
je fais un clique droit sur le bureau
puis j'ouvre les parametre d'affichage 
puis je modifie la mise a l'echelle 
je le met a 175%

* je recompile ...
resultat:
```
La fenetre est ouverte!!Fenetre : 1272 X 695 | Surface : 1272 X 695 | Facteur d'echelle (DPI) : 1.75
```
on peut donc observer des reultats differents

* Conclusion
***

Cette expérience m'a permis de comprendre la différence entre la taille de la fenêtre, la taille de la surface de rendu et le facteur d'échelle du système. Avec une mise à l'échelle de 100 %, j'obtiens une fenêtre et une surface de 1280 x 720 avec un facteur d'échelle de 1. Après avoir modifié la mise à l'échelle de Windows à 175 %, les dimensions de la fenêtre deviennent 1272 x 695 et le facteur d'échelle passe à 1.75.

On constate donc que le facteur d'échelle du système peut modifier les dimensions obtenues par la fenêtre et qu'il est important de prendre en compte le DPI lors du travail avec les dimensions d'affichage.
