# EXERCICE 2:(LES SEPTS DROITS)

* L'objectif ici serra de tester les sept proprietes de configuration d'une fenetre avec :
```
resizable
movable
closable
minimizable
maximizable
canFullscreen
modal
```
* je vais donc modifier mon fichier .cpp permettant d'ouvrir une fenetre basique que vois ci :
```
# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"


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

    }

    window.Close();

    return 0;
}
``` 
* le resizable=false. j'ajoute cfg.resizable = false; dans le MKWindowConfig = "fentre";
```
# include "NKWindow/NKWindow.h"
# include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;
int nkmain(const NkEntryState &state){
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.resizable = false;
```
ici  L'utilisateur ne peut plus redimensionner la fenêtre en modifiant sa largeur ou sa hauteur avec la souris.mais l'utilistateur arrive toujours a redimensionner ceux ci peut etre du a la configuration lier a NKWindow.

* Le movable=false . je retire le cfg.resizable par cfg.movable = false;
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.movable = false;
```
ici L'utilisateur ne peut plus déplacer la fenêtre sur l'écran en utilisant sa barre de titre.mais l'utilistateur arrive toujours a deplacer la fenetre  ceux ci peut etre du a la configuration lier a NKWindow.

* le closable =  false remplacons le cfg.movable = false par cfg.closable = false ; 
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.closable = false ;
```
ici L'utilisateur ne peut plus fermer la fenêtre à l'aide du bouton de fermeture fourni par le système. mais l'utilistateur arrive toujours a fermer la fenetre ceux ci peut etre du a la configuration lier a NKWindow.

* le minimizable . remplacons cfg.closable = false par cfg.minimizable = false;
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
```
ici L'utilisateur ne peut plus minimiser ou réduire la fenêtre à l'aide du bouton de réduction du système. mais l'utilistateur arrive toujours a minimiser la fenetre ceux ci peut etre du a la configuration lier a NKWindow.

* le maximizable = false. Remplacons cfg.minimizable = false par cfg.maximizable = false;

```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.maximizable = false;
```
Ici, l'utilisateur ne peut plus maximiser ou agrandir la fenêtre à l'aide du bouton prévu par le système. mais l'utilistateur arrive toujours a maximiser la fenetre ceux ci peut etre du a la configuration lier a NKWindow.

* le canFullscreen = false. Remplacons cfg.maximizable = false par cfg.canFullscreen = false;
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.canFullscreen = false;
```
Ici, l'utilisateur ne peut plus passer la fenêtre en mode plein écran. mais l'utilistateur arrive toujours a passer en mode plein ecran ceux ci peut etre du a la configuration lier a NKWindow.

* le modal = true. Remplacons cfg.canFullscreen = false par cfg.modal = true;
```
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState &state)
{
    NkWindowConfig cfg;
    cfg.title = "fenetre";
    cfg.modal = true;
```
Ici, la fenêtre devient modale. L'utilisateur doit interagir avec cette fenêtre avant de pouvoir interagir normalement avec les autres fenêtres concernées. mais la fenetre n'est toujours pas modal  ceux ci peut etre du a la configuration lier a NKWindow.

* Conclusion:
***
Cette expérience m'a permis de tester les sept propriétés de NkWindowConfig et de comprendre leur rôle. Chaque propriété permet de contrôler une action différente de l'utilisateur sur la fenêtre, comme la déplacer, la redimensionner, la minimiser, la maximiser ou la mettre en plein écran. 
