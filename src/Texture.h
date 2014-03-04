#pragma once

#include <memory>
#include <SDL.h>
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
                typedef std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_ptr;
                
                Texture() = delete;
                Texture(const Renderer& renderer, const Surface& surface);
                
                Texture(const Texture&) = delete;
                Texture(Texture&& other);
                
                Texture& operator=(const Texture&) = delete;
                Texture& operator=(Texture&&);
                
                virtual ~Texture() = default;
                
            protected:
                texture_ptr texture;
                Geom::Size size;
                
                const Renderer& renderer;
        };
    }
}