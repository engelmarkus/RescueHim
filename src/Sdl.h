#pragma once

#include <map>
#include <type_traits>
#include <SDL.h>
#include <sigc++/sigc++.h>
#include "Singleton.h"
#include "MakeUnique.h"
#include "Window.h"

namespace RescueHim {
    namespace Sdl {
        class Sdl {
            public:
                Sdl();
                virtual ~Sdl();

                void initialize(Uint32 flags);

                template<class W, typename... Args>
                std::shared_ptr<Window> createWindow(Args&&... args) {
                    static_assert(std::is_base_of<Window, W>::value, "W must derive from Sdl::Window");
                    
                    auto wnd = std::make_shared<W>(std::forward<Args>(args)...);
                    auto id = wnd->getId();
                    
                    this->windows.emplace(id, std::move(wnd));
                    
                    return this->windows.at(id);
                }

                virtual bool onQuitRequested();
                
                sigc::signal<void>& quitRequested();
                
                void processEvents();
                
                void run();

            private:
                Sdl(const Sdl&) = delete;
                Sdl& operator=(const Sdl&) = delete;

                Sdl(Sdl&&) = delete;
                Sdl& operator=(Sdl&&) = delete;
                
                // windowID, Fenster
                std::map<Uint32, std::shared_ptr<Window>> windows;
                
                sigc::signal<void> signal_quitRequested;
                
                bool quit;
        };
    }

    using SDL = Singleton<Sdl::Sdl>;
}

