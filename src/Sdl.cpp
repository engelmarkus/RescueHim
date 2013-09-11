#include "Sdl.h"

#include <SDL.h>
#include "SdlError.h"

namespace RescueHim {
    namespace Sdl {
        void Sdl::initialize(Uint32 flags) {
            if (SDL_Init(flags) < 0) {
                throw SdlError{SDL_GetError()};
            }
        }

        Sdl::~Sdl() {
            SDL_Quit();
        }
    }
}

