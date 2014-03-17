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

#include <mutex>
#include <chrono>

class MainWindow : public Window {
public:
    AnimatedTexture biene;
    
    MainWindow()
        : Window("Hauptfenster", Point{100, 100}, Size{640, 480})
        , biene{*this->renderer, SDL_image::instance().load("/home/markus/RescueHim/trunk/data/bee.png"), Size{64, 64}, 6, std::chrono::milliseconds{100}}
        , counter{0}
    {
    }
    
    int counter;
    
    void onRender() override {
        using namespace std::chrono;
        
        static auto start = high_resolution_clock::now();
        //static auto start = SDL_GetTicks();
        //auto s = Surface::fromBmp("/home/markus/test.bmp");
        
        /*{
            std::lock_guard<Surface> lock{*s};
            
            std::cout << "aha" << std::endl;
        }*/
        
        //auto t = Texture{*this->renderer, *s};
        
        //static auto bee = SDL_image::instance().load("/home/markus/RescueHim/trunk/data/bee.png");
        //static AnimatedTexture biene{*this->renderer, bee, Size{64, 64}, 6, std::chrono::milliseconds{150}};
                    
        renderer->setDrawColor(100, 100, 100, 255);
        renderer->clear();
        
        biene.draw(*this->renderer, {150, 350});
        biene.draw(*this->renderer, {200, 300});
        biene.draw(*this->renderer, {250, 250});
        biene.draw(*this->renderer, {300, 300});
        biene.draw(*this->renderer, {350, 350});
        
        //SDL_Rect destrect = Geom::Rect { {100, 100}, t.getSize() };
        
        //renderer->copy(t, Rect{{0, 0}, t.getSize()}, destrect);
        
        //renderer->setDrawColor(255, 255, 255, 255);
        //renderer->drawLine({10, 50}, {50, 100});
        
        renderer->present();   
        counter++;
        
        if (high_resolution_clock::now() - start >= seconds{1}) {
        //if (SDL_GetTicks() - start >= 1000) {
            std::cout << counter << " " << std::endl;
            counter = 0;
            //start = SDL_GetTicks();
            start = high_resolution_clock::now();
        }
    }
};

int main(int argc, char* argv[]) {
    try {
        SDL::instance().initialize(SDL_INIT_VIDEO);
    } catch (const SdlError& error) {
        AppLog<Severity::Error>::log("Error while initializing SDL: ", error.what());
        return 1;
    }
    
    try {
        SDL_image::instance().initialize(IMG_INIT_PNG);
    } catch (const SdlError& error) {
        AppLog<Severity::Error>::log("Error while initializing SDL_image: ", error.what());
        return 1;
    }

   
    auto wnd = SDL::instance().createWindow<MainWindow>();
    
    SDL::instance().run();
    
    
    return 0;
}
