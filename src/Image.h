#pragma once

#include <string>

#include "Singleton.h"
#include "Surface.h"

namespace RescueHim {
    namespace Sdl {
        class Image {
        public:
            Image() = default;
            ~Image();

            void initialize(int flags);

            Surface load(std::string const& filename) const;
        };
    }

    using SDL_image = Singleton<Sdl::Image>;
}
