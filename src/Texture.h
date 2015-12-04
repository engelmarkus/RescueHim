#pragma once

#include <memory>

#include <SDL_render.h>

#include "Size.h"

namespace RescueHim {
    namespace Geom {
        class Point;
    }

    namespace Sdl {
        class Renderer;
        class Surface;

        class Texture {
        public:
            using texture_ptr = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;

            Texture() = delete;

            /**
             * @brief Creates a new Texture from a Surface.
             * @param renderer The Renderer the Texture should be assigned to.
             * @param surface The Surface the Texture should be created from.
             * @remarks The Surface is not needed anymore after successful creation.
             */
            Texture(Renderer const& renderer, Surface const& surface);

            Texture(Texture const&) = delete;
            Texture(Texture&& other);

            Texture& operator=(Texture const&) = delete;
            Texture& operator=(Texture&&);

            virtual ~Texture() = default;

            /**
             * @brief Returns the Size of the Texture.
             */
            virtual Geom::Size getSize() const;

            /**
             * @brief Draws the Texture at the specified position using the Renderer
             * that has been passed at construction.
             * @param dest The upper left corner of the rectangle where the Texture should be drawn.
             */
            virtual void draw(Geom::Point dest);

            SDL_Texture* getSdlTexture() const;

        protected:
            texture_ptr texture;
            Geom::Size size;

            Renderer const& renderer;
        };
    }
}
