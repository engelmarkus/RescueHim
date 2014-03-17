#include "Image.h"

#include <memory>
#include <utility>

#include <SDL_image.h>
#include <SDL_surface.h>

#include "SdlError.h"
#include "Surface.h"

namespace RescueHim {
    namespace Sdl {
        Image::~Image() {
            IMG_Quit();
        }
        
        void Image::initialize(int flags) {
            auto result = IMG_Init(flags);
            
            if ((result & flags) != flags) {
                throw SdlError{IMG_GetError()};
            }
        }
        
        Surface Image::load(const std::string& filename) const {
            auto s = Surface::surface_ptr{IMG_Load(filename.c_str()), SDL_FreeSurface};
            
            if (s == nullptr) {
                throw SdlError{IMG_GetError()};
            }
            
            return Surface{std::move(s)};
        }
    }
}
