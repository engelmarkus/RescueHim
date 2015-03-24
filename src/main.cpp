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

class Control {
public:
    Control(Point position, Size size) : position{position}, size{size} {
        
    }
    
    virtual ~Control() {}
    
    virtual void onMouseEnter() {}
    virtual void onMouseMove(Point coordinates) {}
    virtual void onMouseLeave() {}
    
    virtual void onClick(Point p) {}
    
    virtual void draw(const Renderer& renderer) = 0;
    
//protected:
    Point position;
    Size size;
};

class Button : public Control {
public:
    Button(Point position, Size size, const std::string& text) : Control(position, size), text{text} {
    }
    
    virtual ~Button() {
    }
    
    virtual void onMouseEnter() override {
        mouseOver = true;
    }
    
    virtual void onMouseLeave() override {
        mouseOver = false;
    }
    
    virtual void onClick(Point) override {
        this->clicked.emit();
    }
    
    virtual void draw(const Renderer& renderer) override {
        if (!inactiveTexture) {
            this->updateTextures(renderer);
        }
        
        if (!active) {
            inactiveTexture->draw(position);
        }
        else {
            if (!mouseOver) {
                normalTexture->draw(position);
            }
            else {
                hoverTexture->draw(position);
            }
        }
    }
    
    const sigc::signal<void>& signal_clicked() {
        return this->clicked;
    }
    
//protected:
    std::string text;
    bool mouseOver;
    bool active;
    
    sigc::signal<void> clicked;
    
    SDL_Color inactiveColor = { 100, 100, 100, 255 };
    SDL_Color normalColor = { 100, 100, 150, 255 };
    SDL_Color hoverColor = { 150, 150, 200, 255 };
    
    std::unique_ptr<Texture> inactiveTexture;
    std::unique_ptr<Texture> normalTexture;
    std::unique_ptr<Texture> hoverTexture;
    
    void updateTextures(const Renderer& renderer) {
        inactiveTexture = std::make_unique<Texture>(renderer, Surface{size, inactiveColor.r, inactiveColor.g, inactiveColor.b, inactiveColor.a});
        normalTexture = std::make_unique<Texture>(renderer, Surface{size, normalColor.r, normalColor.g, normalColor.b, normalColor.a});
        hoverTexture = std::make_unique<Texture>(renderer, Surface{size, hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a});
        // render text
    }
};

class Panel : public Control {
public:
    using Control::Control;
    
    virtual ~Panel() {}
    
    virtual void onMouseMove(Point coordinates) {
        auto child = std::find_if(std::begin(children), std::end(children), [&](const std::unique_ptr<Control>& c) { return Rect{c->position, c->size}.contains(coordinates); });
        
        if (child != std::end(children)) {
            (*child)->onMouseEnter();
        }
    }
    
    virtual void draw(const Renderer& renderer) override {
        for (const auto& child : children) {
            child->draw(renderer);
        }
    }
    
//protected:
    std::vector<std::unique_ptr<Control>> children;
};

#include "Gui.h"

namespace RescueHim {
    class MainWindow2 : public Sdl::Window {
        public:
            MainWindow2()
                : Window("Hauptfenster", Point{100, 100}, Size{640, 480})
            {
                auto p = new Panel(Point{0, 0}, Size{640, 480});
                p->children.emplace_back(std::make_unique<Button>(Point{100, 100}, Size{100, 25}, "hallo"));
                m.toplevel = p;
            }
            
            virtual void onRender() {
                auto& r = this->getRenderer();
                
                r.setDrawColor(0, 0, 0, 255);
                r.clear();
        
                m.toplevel->draw(this->getRenderer());
                
                r.present();
            }
            
            virtual void onMouseMove(Point position) override {
                m.toplevel->onMouseMove(position);
                
                AppLog<Severity::Info>::log("%d x %d", position.x, position.y);
            }

            Manager m;
    };
}


int main(int argc, char* argv[]) {
    //Game g;
    //g.initialize();
    Lua::Lua l;
    
    
    /*try {
        SDL::instance().initialize(SDL_INIT_VIDEO);
    } catch (const SdlError& error) {
        AppLog<Severity::Error>::log("Error while initializing SDL: ", error.what());
        std::exit(1);
    }
    
    try {
        SDL_image::instance().initialize(IMG_INIT_PNG);
    } catch (const SdlError& error) {
        AppLog<Severity::Error>::log("Error while initializing SDL_image: ", error.what());
        std::exit(1);
    }

    auto wnd = SDL::instance().createWindow<MainWindow2>();
    
    SDL::instance().run();
    */
    return 0;
}
