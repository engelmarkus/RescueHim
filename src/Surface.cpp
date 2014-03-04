#include "Surface.h"

#include <utility>
#include <SDL_error.h>
#include <SDL_surface.h>
#include "SdlError.h"
#include "Size.h"
#include "MakeUnique.h"

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

        Surface::Surface(Surface::surface_ptr surface)
            : surface{std::move(surface)}
        {
        }
        
        /*Surface::Surface(SDL_Surface*&& s)
            : surface{nullptr, SDL_FreeSurface}
        {
            if (s == nullptr) {
                throw std::invalid_argument{"Trying to move from nullptr."};
            }

            this->surface.reset(s);
            s = nullptr;
        }*/
        
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
        
        std::unique_ptr<Surface> Surface::fromBmp(const std::string& filename) {
            auto surface = Surface::surface_ptr{SDL_LoadBMP(filename.c_str()), SDL_FreeSurface};
            
            if (surface == nullptr) {
                throw SdlError{SDL_GetError()};
            }
            
            return std::make_unique<Surface>(std::move(surface));
        }

        /*SDL_Surface& Surface::getSurface() {
            return *this->surface;
        }

        const SDL_Surface& Surface::getSurface() const {
            return *this->surface;
        }*/
        
        unsigned int Surface::getWidth() const {
            return this->surface->w;
        }
        
        unsigned int Surface::getHeight() const {
            return this->surface->h;
        }
        
        Geom::Size Surface::getSize() const {
            return Geom::Size { this->getWidth(), this->getHeight() };
        }
        
        
        void swap(Surface& a, Surface& b) noexcept {
            std::swap(a.surface, b.surface);
        }
    }
}

