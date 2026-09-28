# EXERCICE 7: (LE GLISSER QUI SORT)

* pour cette exercice je vais tester le glisser de la souris en deux parties. D'abord je vais faire le test sans capture et ensuite je vais refaire la meme chose avec la capture pour voir ce qui change.j'ai utiliser ce programme:
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
        std::cout << "La fenetre est ouverte!!" << std::endl;
    }

    bool running = true;

    NkEventSystem &events = NkEvents();

    events.AddEventCallback<NkWindowCloseEvent>(
        [&](NkWindowCloseEvent *)
        {
            running = false;
        }
    );

    // Affichage des mouvements de la souris
    events.AddEventCallback<NkMouseMoveEvent>(
        [&](NkMouseMoveEvent *e)
        {
            std::cout << "Souris : "
                      << e->GetX()
                      << " ; "
                      << e->GetY()
                      << std::endl;
        }
    );

    // Activation de la capture avec le clic gauche
    events.AddEventCallback<NkMouseButtonPressEvent>(
        [&](NkMouseButtonPressEvent *e)
        {
            if (e->IsLeft())
            {
                std::cout << "Clic gauche : capture active"
                          << std::endl;

                window.CaptureMouse(true);
            }
        }
    );

    // Liberation de la capture avec le relachement du clic gauche
    events.AddEventCallback<NkMouseButtonReleaseEvent>(
        [&](NkMouseButtonReleaseEvent *e)
        {
            if (e->IsLeft())
            {
                std::cout << "Clic gauche : capture liberee"
                          << std::endl;

                window.CaptureMouse(false);
            }
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

* je commence d'abord sans utiliser la capture de la souris.
Pour voir les mouvements de la souris je vais utiliser NkMouseMoveEvent :

```
events.AddEventCallback<NkMouseMoveEvent>(
    [&](NkMouseMoveEvent *e) {
        std::cout << "Souris : "
                  << e->GetX()
                  << " ; "
                  << e->GetY()
                  << std::endl;
    }
);
```

* je construit et j'execute le programme.
resultat:
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
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.06s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
Lorsque je bouge la souris dans la fenetre, les positions sont affichees dans le terminal.

RESULTAT :

```
La fenetre est ouverte!!
Souris : 1269 ; 268
Souris : 1245 ; 311
Souris : 1222 ; 356
Souris : 1204 ; 387
Souris : 1187 ; 419
Souris : 1174 ; 440
Souris : 1167 ; 453
Souris : 1163 ; 461
Souris : 1160 ; 465
Souris : 1160 ; 467
Souris : 1154 ; 468
Souris : 1150 ; 471
Souris : 1144 ; 474
Souris : 1138 ; 476
Souris : 1132 ; 478
Souris : 1124 ; 481
Souris : 1113 ; 484
Souris : 1100 ; 488
Souris : 1086 ; 491
Souris : 1069 ; 494
Souris : 1045 ; 498
Souris : 1020 ; 500
Souris : 996 ; 500
Souris : 977 ; 500
Souris : 955 ; 500
Souris : 927 ; 499
Souris : 899 ; 497
Souris : 878 ; 495
Souris : 850 ; 492
Souris : 816 ; 488
Souris : 780 ; 483
Souris : 749 ; 480
Souris : 715 ; 475
Souris : 679 ; 473
Souris : 648 ; 471
Souris : 627 ; 471
Souris : 610 ; 471
Souris : 597 ; 471
Souris : 586 ; 471
Souris : 577 ; 471
Souris : 570 ; 471
Souris : 565 ; 471
Souris : 562 ; 471
Souris : 559 ; 471
Souris : 557 ; 471
Souris : 522 ; 473
Souris : 472 ; 479
Souris : 411 ; 485
Souris : 356 ; 493
Souris : 289 ; 506
Souris : 222 ; 522
Souris : 159 ; 545
Souris : 93 ; 573
Souris : 43 ; 597
Souris : 588 ; 707
Souris : 600 ; 674
Souris : 609 ; 651
Souris : 615 ; 637
Souris : 623 ; 612
Souris : 630 ; 590
Souris : 636 ; 568
Souris : 640 ; 552
Souris : 643 ; 540
Souris : 647 ; 521
Souris : 650 ; 503
Souris : 652 ; 485
Souris : 655 ; 467
Souris : 657 ; 449
Souris : 659 ; 426
Souris : 662 ; 401
Souris : 664 ; 387
Souris : 665 ; 375
Souris : 666 ; 368
Souris : 667 ; 363
Souris : 667 ; 360
Souris : 668 ; 357
Souris : 668 ; 355
Souris : 668 ; 354
Souris : 668 ; 352
Souris : 668 ; 351
Souris : 668 ; 350
```

* je commence ensuite un glisser dans la fenetre en maintenant le bouton gauche de la souris et je continue a deplacer la souris vers l'exterieur de la fenetre.
je constate que lorsque la souris sort de la fenetre, les positions ne sont plus affichees.

Donc la fenetre ne recoit plus les mouvements de la souris une fois que celle-ci est sortie.


* maintenant je vais refaire le meme test mais cette fois je vais utiliser la capture de la souris.
Pour cela je vais utiliser :

```
window.CaptureMouse(true);
```
pour activer la capture et :

```
window.CaptureMouse(false);
```
pour l'arreter.

* je vais donc activer la capture quand je fais un clic gauche et la liberer quand je relache le bouton.
```
events.AddEventCallback<NkMouseButtonPressEvent>(
    [&](NkMouseButtonPressEvent *e) {
        if (e->IsLeft()) {
            std::cout << "Clic gauche : capture active"
                      << std::endl;

            window.CaptureMouse(true);
        }
    }
);

events.AddEventCallback<NkMouseButtonReleaseEvent>(
    [&](NkMouseButtonReleaseEvent *e) {
        if (e->IsLeft()) {
            std::cout << "Clic gauche : capture liberee"
                      << std::endl;

            window.CaptureMouse(false);
        }
    }
);
```

je garde aussi l'evenement qui permet d'afficher les mouvements :
```
events.AddEventCallback<NkMouseMoveEvent>(
    [&](NkMouseMoveEvent *e) {
        std::cout << "Souris : "
                  << e->GetX()
                  << " ; "
                  << e->GetY()
                  << std::endl;
    }
);
```

* je construit et j'execute le programme.
je clique sur le bouton gauche dans la fenetre et je garde le bouton enfonce. Ensuite je deplace la souris vers l'exterieur de la fenetre.
RESULTAT :

```
Clic gauche : capture active
Souris : 667 ; 350
Souris : 666 ; 350
Souris : 663 ; 352
Souris : 661 ; 353
Souris : 656 ; 355
Souris : 650 ; 357
Souris : 642 ; 360
Souris : 636 ; 362
Souris : 628 ; 364
Souris : 618 ; 366
Souris : 609 ; 367
Souris : 598 ; 369
Souris : 590 ; 369
Souris : 584 ; 370
Souris : 579 ; 370
Souris : 576 ; 370
Souris : 572 ; 370
Souris : 568 ; 370
Souris : 563 ; 370
Souris : 558 ; 370
Souris : 551 ; 369
Souris : 540 ; 366
Souris : 529 ; 363
Souris : 518 ; 360
Souris : 507 ; 358
Souris : 496 ; 354
Souris : 484 ; 351
Souris : 467 ; 347
Souris : 451 ; 344
Souris : 434 ; 339
Souris : 423 ; 334
Souris : 409 ; 330
Souris : 394 ; 323
Souris : 375 ; 316
Souris : 353 ; 311
Souris : 334 ; 305
Souris : 317 ; 300
Souris : 301 ; 295
Souris : 279 ; 289
Souris : 257 ; 283
Souris : 244 ; 281
Souris : 233 ; 279
Souris : 226 ; 277
Souris : 220 ; 276
Souris : 215 ; 275
Souris : 210 ; 274
Souris : 206 ; 273
Souris : 200 ; 271
Souris : 193 ; 270
Souris : 187 ; 269
Souris : 177 ; 267
Souris : 168 ; 266
Souris : 158 ; 265
Souris : 149 ; 263
Souris : 138 ; 262
Souris : 128 ; 261
Souris : 120 ; 260
Souris : 113 ; 259
Souris : 108 ; 259
Souris : 105 ; 259
Souris : 102 ; 259
Souris : 97 ; 259
Souris : 91 ; 260
Souris : 85 ; 262
Souris : 82 ; 263
Souris : 79 ; 264
Souris : 78 ; 265
Souris : 76 ; 266
Souris : 75 ; 267
Souris : 73 ; 268
Souris : 72 ; 268
Souris : 72 ; 269
Souris : 71 ; 269
Souris : 68 ; 271
Souris : 62 ; 275
Souris : 59 ; 278
Souris : 57 ; 279
Souris : 55 ; 281
Souris : 54 ; 282
Souris : 53 ; 283
Souris : 52 ; 284
Souris : 51 ; 284
Souris : 50 ; 284
Souris : 49 ; 284
Souris : 47 ; 283
Souris : 45 ; 283
Souris : 42 ; 282
Souris : 38 ; 282
Souris : 32 ; 282
Souris : 26 ; 282
Souris : 21 ; 282
Souris : 13 ; 280
Souris : 2 ; 278
Souris : -12 ; 275
Souris : -26 ; 271
Souris : -38 ; 269
Souris : -47 ; 266
Souris : -56 ; 264
Souris : -64 ; 262
Souris : -73 ; 260
Souris : -89 ; 257
Souris : -110 ; 252
Souris : -129 ; 247
Souris : -142 ; 245
Souris : -153 ; 243
Souris : -163 ; 240
Souris : -168 ; 240
Souris : -174 ; 239
Souris : -177 ; 239
Souris : -180 ; 238
Souris : -181 ; 237
Souris : -183 ; 237
Souris : -185 ; 237
Souris : -186 ; 237
Souris : -187 ; 237
Souris : -188 ; 237
Souris : -189 ; 237
Souris : -190 ; 237
Souris : -191 ; 237
Clic gauche : capture liberee
```
* je constate que cette fois les positions continuent a s'afficher meme lorsque la souris est sortie de la fenetre.
Les valeurs deviennent negatives lorsque je depasse le bord de la fenetre. Cela montre donc que les mouvements continuent a etre recuperes meme si la souris est a l'exterieur.
Lorsque je relache le bouton gauche, la capture est liberee.

* Conclusion:
***
Cette experience m'a permis de voir la difference entre le glisser sans capture et le glisser avec capture.
Sans capture, lorsque la souris sort de la fenetre, les mouvements ne sont plus recuperes normalement.
Avec capture, les mouvements continuent a etre recuperes meme lorsque la souris est sortie de la fenetre.
Donc la capture est utile lorsque je veux commencer une action dans la fenetre et continuer cette action meme si la souris sort de la fenetre.
