#pragma once

#include <map>
#include <memory>
#include <type_traits>
#include <utility>

#include <SDL_stdinc.h>
#include <sigc++/signal.h>

#include "Singleton.h"

#include "Window.h"

namespace RescueHim {
    namespace Sdl {
        //class Window;

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

            // Wenn wir mit lua ein Fenster erzeugen wollen, müssen wir das ja noch
            // von Hand hinzufügen können. Dann können wir aber das Template createWindow nicht
            // benutzen, weil wir den Klassentypen noch gar nicht kennen zur Compilezeit.
            void addWindow(std::shared_ptr<Window> wnd) {
                this->windows.emplace(wnd->getId(), wnd);
            }

            virtual bool onQuitRequested();

            sigc::signal<void>& quitRequested();

            sigc::signal<void>& updateSignal();
            sigc::signal<void>& renderSignal();

            void processEvents();

            void run();

        private:
            Sdl(Sdl const&) = delete;
            Sdl& operator=(Sdl const&) = delete;

            Sdl(Sdl&&) = delete;
            Sdl& operator=(Sdl&&) = delete;

            // windowID, Fenster
            std::map<Uint32, std::shared_ptr<Window>> windows;

            sigc::signal<void> signal_quitRequested;

            sigc::signal<void> signal_update;
            sigc::signal<void> signal_render;

            bool quit;
        };
    }

    using SDL = Singleton<Sdl::Sdl>;
}
