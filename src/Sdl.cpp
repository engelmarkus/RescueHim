#include "Sdl.h"

#include <chrono>
#include <thread>
#include <SDL.h>
#include "SdlError.h"
#include "ChronoLiterals.h"

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
                    case SDL_QUIT:
                        quit = this->onQuitRequested();
                        this->signal_quitRequested.emit();
                        break;
                }
            }
        }
        
        void Sdl::run() {
            using namespace std::chrono;
            
            auto time_per_frame = 50_ms;
            
            while (!quit) {
                auto start_time = steady_clock::now();
                
                this->processEvents();
                
                // Draw-Thread?
                
                auto elapsed_time = steady_clock::now() - start_time;
                
                if (elapsed_time < time_per_frame) {
                    std::this_thread::sleep_for(time_per_frame - elapsed_time);
                }
            }
        }
    }
}

