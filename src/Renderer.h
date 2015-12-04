#pragma once

#include <memory>

#include <SDL_render.h>

namespace RescueHim {
    namespace Geom {
        class Point;
        class Rect;
    }

    namespace Sdl {
        class Texture;
        class Window;

        class Renderer final {
        public:
            using renderer_ptr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

            Renderer() = delete;
            Renderer(Window const& window);

            Renderer(Renderer const&) = delete;
            Renderer(Renderer&& other);

            Renderer& operator=(Renderer const&) = delete;
            Renderer& operator=(Renderer&& other);

            ~Renderer() = default;

            void clear();
            void present();

            void setDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

            void copy(Texture const& texture, Geom::Rect const& src, Geom::Rect const& dest);

            void drawLine(Geom::Point const& p1, Geom::Point const& p2);

            SDL_Renderer* getSdlRenderer() const;

            friend class Window;
            friend void swap(Renderer& a, Renderer& b) noexcept;

        private:
            renderer_ptr renderer;
        };
    }
}
