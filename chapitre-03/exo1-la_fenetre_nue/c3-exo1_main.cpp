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