#include "Surface.h"

#include <stdexcept>
#include <SDL_error.h>
#include <SDL_surface.h>
#include "SdlError.h"
#include "Size.h"

namespace RescueHim {
    namespace Sdl {
        Surface::Surface(const Geom::Size& size)
            : surface{nullptr, SDL_FreeSurface}
        {
            surface.reset(SDL_CreateRGBSurface(0, size.width, size.height, 32, 0, 0, 0, 0));

            if (surface == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }

        Surface::Surface(SDL_Surface*&& s)
            : surface{nullptr, SDL_FreeSurface}
        {
            if (s == nullptr) {
                throw std::invalid_argument{"Trying to move from nullptr."};
            }

            this->surface.reset(s);
            s = nullptr;
        }

        Surface::Surface(const Surface& s)
            : surface{nullptr, SDL_FreeSurface}
        {
            surface.reset(SDL_ConvertSurface(s.surface.get(), s.surface->format, s.surface->flags));
            
            if (surface == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }

        Surface& Surface::operator=(const Surface& s) {
            if (this != &s) {
                this->surface.reset(SDL_ConvertSurface(s.surface.get(), s.surface->format, s.surface->flags));

                if (surface == nullptr) {
                    throw SdlError{SDL_GetError()};
                }
            }

            return *this;
        }

        SDL_Surface& Surface::getSurface() {
            return *this->surface;
        }

        const SDL_Surface& Surface::getSurface() const {
            return *this->surface;
        }
    }
}

