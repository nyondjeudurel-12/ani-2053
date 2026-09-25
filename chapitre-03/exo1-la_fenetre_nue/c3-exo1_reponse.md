# EXERCICE 1: (LA FENETRE NUE)

* J'ai commence par configurer mon environnement NKWindow.
* j'ai par la suite creer le plus petit programme qui ouvre une fenêtre, la garde ouverte, et se termine proprement.
voici les lignes de code :
```
# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"
#include <iostream>

using namespace nkentseu;
int nkmain(const NkEntryState &state){
    NkWindowConfig cfg;
    cfg.title = "fenetre";

    NkWindow window(cfg);
    if(!window.IsOpen()){
        logger.Error("[app] creation fenetre echouer!!");
        return -1;
    }else{
        std::cout<<"La fenetre est ouverte!!";
    }

    bool running = true;
    NkEventSystem &events = NkEvents();
    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *) {
            running = false;
        }
    );
    while (running && window.IsOpen()) {
            events.PollEvents();
            NkClock::Sleep((int64)10);

    }

    window.Close();

    return 0;
}
```
* resultat de la compilation:
```
PS C:\Users\nyond\OneDrive\Desktop\MY_WORKSPACE> jenga build

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
│  ✓ Build Successful                                                             Time: 6.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           6.06s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\nyond\OneDrive\Desktop\MY_WORKSPACE> jenga run  

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


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  MY_WORKSPACE.exe
     C:\Users\nyond\OneDrive\Desktop\MY_WORKSPACE\Build\Bin\Debug-Windows\MY_WORKSPACE\MY_WORKSPACE.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

La fenetre est ouverte!!
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (9.40s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

```

* Mon programme compte 36 lignes si on admet les espaces et 30 lignes sans les espaces .

* Correspondance avec le chapitre

 nkmain()  Section sur le point d'entrée de l'application 
 NkWindowConfig  Section sur la configuration de NKWindow
 NkWindow window(cfg)  Section sur la création de la fenêtre  IsOpen()  Section sur la boucle de vie de la fenêtre 
 PollEvents() Section sur le traitement des événements 
 NkWindowCloseEvent  Section sur les événements de fenêtre 
 window.Close()  Section sur la fermeture de la fenêtre 

* Conclusion:
***
 Cet exercice m’a permis de comprendre le fonctionnement de base de NKWindow : créer une fenêtre, traiter ses événements, détecter sa fermeture et terminer proprement le programme. J’ai également pu relier les différentes parties du code aux notions présentées dans le chapitre.