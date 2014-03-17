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
                typedef std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_ptr;

                Renderer() = delete;
                Renderer(const Window& window);
                
                Renderer(const Renderer&) = delete;
                Renderer(Renderer&& other);
                
                Renderer& operator=(const Renderer&) = delete;
                Renderer& operator=(Renderer&& other);
                
                ~Renderer() = default;
                
                void clear();
                void present();
                
                void setDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
                
                void copy(const Texture& texture, const Geom::Rect& src, const Geom::Rect& dest);
                
                void drawLine(const Geom::Point& p1, const Geom::Point& p2);
                
                SDL_Renderer* getSdlRenderer() const;
                
                friend class Window;
                friend void swap(Renderer& a, Renderer& b) noexcept;
                
            private:
                renderer_ptr renderer;
        };
    }
}
