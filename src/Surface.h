#pragma once

#include <memory>
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
                /**
                  * @brief Creates a new empty Surface with the given size.
                  */
                Surface(const Geom::Size& size);

                /**
                  * @brief Creates a new Surface by taking ownership of the given SDL_Surface.
                  */
                Surface(SDL_Surface*&& s);

                Surface(const Surface& s);
                Surface& operator=(const Surface& s);

                Surface(Surface&&) noexcept = default;
                Surface& operator=(Surface&&) = default;

                ~Surface() = default;

                SDL_Surface& getSurface();
                const SDL_Surface& getSurface() const;

            private:
                std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;
        };
    }
}

