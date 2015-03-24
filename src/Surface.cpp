#include "Surface.h"

#include <utility>

#include <SDL_error.h>
#include <SDL_surface.h>

#include "SdlError.h"
#include "Size.h"

#include "Rect.h"

namespace RescueHim {
    namespace Sdl {
        Surface::Surface(const Geom::Size& size, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
            : surface{nullptr, SDL_FreeSurface}
        {
            surface.reset(SDL_CreateRGBSurface(0, size.width, size.height, 32, 0, 0, 0, 0));
            
            auto re = SDL_Rect(Geom::Rect{0,0,640,480});
            SDL_FillRect(surface.get(), &re, SDL_MapRGBA(surface.get()->format, r, g, b, a));

            if (surface == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }

        Surface::Surface(Surface::surface_ptr surface)
            : surface{std::move(surface)}
        {
        }
        
        Surface::Surface(const Surface& other)
            : surface{nullptr, SDL_FreeSurface}
        {
            surface.reset(SDL_ConvertSurface(other.surface.get(), other.surface->format, other.surface->flags));
            
            if (surface == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }

        Surface::Surface(Surface&& other) noexcept
            : surface{nullptr, SDL_FreeSurface}
        {
            swap(*this, other);
        }

        Surface& Surface::operator=(Surface other) {
            swap(*this, other);
            return *this;
        }
        
        unsigned int Surface::getWidth() const {
            return this->surface->w;
        }
        
        unsigned int Surface::getHeight() const {
            return this->surface->h;
        }
        
        Geom::Size Surface::getSize() const {
            return Geom::Size { this->getWidth(), this->getHeight() };
        }
        
        SDL_Surface* Surface::getSdlSurface() const {
            return this->surface.get();
        }
        
        bool Surface::mustLock() const {
            return SDL_MUSTLOCK(this->surface.get());
        }
        
        void Surface::lock() {
            auto result = SDL_LockSurface(this->surface.get());
            
            if (result != 0) {
                throw SdlError{SDL_GetError()};
            }
        }
        
        void Surface::unlock() {
            SDL_UnlockSurface(this->surface.get());
        }
        
        
        void swap(Surface& a, Surface& b) noexcept {
            std::swap(a.surface, b.surface);
        }
    }
}
