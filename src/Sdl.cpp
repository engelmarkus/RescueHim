#include "Sdl.h"

#include <chrono>
#include <ratio>
#include <thread>

#include <SDL.h>

#include "SdlError.h"
#include "Window.h"

namespace RescueHim {
    namespace Sdl {
        void Sdl::initialize(Uint32 flags) {
            if (SDL_Init(flags) < 0) {
                throw SdlError{SDL_GetError()};
            }
        }

        Sdl::Sdl()
            : quit{false}
        {
        }

        Sdl::~Sdl() {
            windows.clear();
            SDL_Quit();
        }

        bool Sdl::onQuitRequested() {
            return true;
        }

        sigc::signal<void>& Sdl::quitRequested() {
            return signal_quitRequested;
        }

        sigc::signal<void>& Sdl::updateSignal() {
            return signal_update;
        }

        sigc::signal<void>& Sdl::renderSignal() {
            return signal_render;
        }

        void Sdl::processEvents() {
            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                case SDL_MOUSEMOTION:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEWHEEL:
                case SDL_TEXTEDITING:
                case SDL_TEXTINPUT:
                case SDL_WINDOWEVENT:
                    // Haben alle eine windowID zugeordnet
                    // Weil SDL_Event eine union ist und die windowID immer an
                    // derselben Stelle steht, ist es egal, auf welchen Member
                    // wir genau zugreifen.
                    this->windows.at(event.window.windowID)->processEvents(event);
                    break;

                case SDL_USEREVENT:
                    for (auto& wnd : this->windows) {
                        wnd.second->onRender();
                    }
                    break;

                case SDL_QUIT:
                    quit = this->onQuitRequested();
                    this->signal_quitRequested.emit();
                    break;
                }
            }
        }

        void Sdl::run() {
            using namespace std::chrono;
            using clock = high_resolution_clock;

            const int FPS = 60;
            duration<int, std::ratio<1, FPS>> renderInterval{1};

            auto updateInterval = renderInterval / 4.0;

            int renderCounter = 0;

            SDL_UserEvent u{};
            u.type = SDL_USEREVENT;

            SDL_Event e{};
            e.type = SDL_USEREVENT;

            e.user = u;

            auto start_time = clock::now();

            while (!quit) {
                // Queue rendering if renderInterval has passed
                if (renderCounter % 4 == 0) {
                    SDL_PushEvent(&e);
                    signal_render.emit();
                }

                renderCounter++;

                this->processEvents();
                signal_update.emit();

                auto elapsed_time = clock::now() - start_time;

                if (elapsed_time < updateInterval) {
                    std::this_thread::sleep_for(updateInterval - elapsed_time);
                }

                // wahrscheinlich zu lang geschlafen
                // start_time zurücksetzen auf die Zeit, die hätte vergehen dürfen.
                start_time += duration_cast<clock::duration>(updateInterval);
            }
        }
    }
}
