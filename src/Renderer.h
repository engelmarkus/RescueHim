#pragma once

#include <memory>
#include <SDL.h>

namespace RescueHim {
    namespace Geom {
        class Point;
        class Rect;
    }
    
    namespace Sdl {
        class Window;
        class Texture;
        
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
                
                friend class Window;
                friend void swap(Renderer& a, Renderer& b);
                
            private:
                renderer_ptr renderer;
        };
    }
}