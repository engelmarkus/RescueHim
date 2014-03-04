#include <iostream>
#include <memory>
#include <map>

#include <SDL.h>
#include "Logger.h"
#include "Sdl.h"
#include "SdlError.h"
#include "Window.h"

#include "Rect.h"
#include "Point.h"
#include "Size.h"
#include "MakeUnique.h"

using namespace RescueHim;
using namespace RescueHim::Sdl;
using namespace RescueHim::Geom;

/*
 * Das Eventhandling muss ja per-Window passieren, weil man jetzt auch Mehrfensteranwendungen in sdl erstellen kann.
 * Oder sollte es an einem zentralen Ort passieren und die Events werden an das gerade aktuelle Fenster weitergeleitet?
 * Kann man denn bei den Events feststellen, zu welchem Fenster sie gehören? Ja, aber nicht bei allen.
 * Die Application-Klasse hat die einzige Eventloop und kennt alle Fenster, sodass sie die Events an die Fenster
 * weiterverteilt. Das Fenster hat die processEvents-Methode, die dann auf die einzelnen virtuellen Methoden dispatcht.
 * 
 */

int main(int argc, char* argv[]) {
    try {
        SDL::instance().initialize(SDL_INIT_VIDEO);
    } catch (const SdlError& error) {
        AppLog<Severity::Error>::log("Error while initializing SDL: ", error.what());
        return 1;
    }

   
    auto wnd = SDL::instance().createWindow<Window>("Hauptfenster", Point{100, 100}, Size{200, 200});
    
    SDL::instance().run();
    
    return 0;
}

