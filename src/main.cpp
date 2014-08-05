#include <iostream>
#include <memory>
#include <map>

#include <SDL.h>
#include <SDL_image.h>
#include "Logger.h"
#include "Sdl.h"
#include "Image.h"
#include "SdlError.h"
#include "Window.h"

#include "Rect.h"
#include "Point.h"
#include "Size.h"
#include "MakeUnique.h"

#include "Surface.h"
#include "Texture.h"
#include "AnimatedTexture.h"
#include "Game.h"

#include "Scripting/Lua.h"

using namespace RescueHim;
using namespace RescueHim::Sdl;
using namespace RescueHim::Geom;

#include <sigc++/sigc++.h>

#include <algorithm>
#include <mutex>
#include <chrono>
#include <vector>

/*
 * Welche Zustände haben wir denn?
 * - Intro abspielen
 * - Hauptmenü
 *   - Einzelspieler
 *   - Mehrspieler (einer steuert den Menschen, einer den Wolf, rundenbasiert)
 * - Einstellungen
 *   - Grafik
 *   - Audio
 *   - Steuerung
 * 
 * Irgendwie so. Sachen, die mehr als einen Zustand beeinflussen, werden in der Game-Klasse gespeichert.
 * Wie funktioniert die State Machine?
 * 
 * Die update-Methode der GameStates macht ggf. den state switch.
 * Beim switchen aufpassen... die update-methode ist ja ein member... sobald man aber switchState aufgerufen hat,
 * muss man sofort returnen, weil der this-pointer ungültig wird. die Game-Klasse managt den zustand ja in einem
 * unique_ptr...
 */


int main(int argc, char* argv[]) {
    //Game g;
    //g.initialize();
    Lua::Lua l;
    
    return 0;
}
