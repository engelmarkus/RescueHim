#include "Texture.h"

#include "Renderer.h"
#include "Surface.h"
#include "SdlError.h"
#include "Point.h"

namespace RescueHim {
    namespace Sdl {
        Texture::Texture(const Renderer& renderer, const Surface& surface)
            : texture{nullptr, SDL_DestroyTexture}
            , size{surface.getSize()}
            , renderer{renderer}
        {
        }
    }
}