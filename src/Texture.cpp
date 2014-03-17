#include "Texture.h"

#include <SDL_error.h>

#include "Point.h"
#include "Rect.h"
#include "Renderer.h"
#include "SdlError.h"
#include "Size.h"
#include "Surface.h"

namespace RescueHim {
    namespace Sdl {
        Texture::Texture(const Renderer& renderer, const Surface& surface)
            : texture{nullptr, SDL_DestroyTexture}
            , size{surface.getSize()}
            //, renderer{renderer}
        {
            texture.reset(SDL_CreateTextureFromSurface(renderer.getSdlRenderer(), surface.getSdlSurface()));
            
            if (texture == nullptr) {
                throw SdlError{SDL_GetError()};
            }
        }
        
        Geom::Size Texture::getSize() const {
            return this->size;
        }
        
        void Texture::draw(const Renderer& renderer, Geom::Point dest) {
            const_cast<Renderer&>(renderer).copy(*this, {{0, 0}, size}, {dest, size});
        }
        
        SDL_Texture* Texture::getSdlTexture() const {
            return this->texture.get();
        }
    }
}
