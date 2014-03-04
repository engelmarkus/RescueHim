#pragma once

#include <memory>
#include <string>
#include <SDL_surface.h>

namespace RescueHim {
    namespace Geom {
        class Size;
    }

    namespace Sdl {
        /**
          * @brief Encapsulates an SDL_Surface.
          */
        class Surface final {
            public:
                typedef std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface_ptr;
                
                /**
                  * @brief Creates a new empty Surface with the given size.
                  */
                Surface(const Geom::Size& size);

                /**
                  * @brief Creates a new Surface by taking ownership of the given SDL_Surface.
                  */
                //Surface(SDL_Surface*&& s);
                Surface(surface_ptr surface);

                Surface(const Surface& other);
                Surface(Surface&& other) noexcept;
                
                Surface& operator=(Surface other);

                ~Surface() = default;
                
                static std::unique_ptr<Surface> fromBmp(const std::string& filename);
                
                //SDL_Surface& getSurface();
                //const SDL_Surface& getSurface() const;
                
                unsigned int getWidth() const;
                unsigned int getHeight() const;
                
                Geom::Size getSize() const;

                friend void swap(Surface& a, Surface& b) noexcept;
                
            private:
                //std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;
                surface_ptr surface;
        };
    }
}

