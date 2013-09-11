#pragma once

#include <SDL.h>
#include "Singleton.h"

namespace RescueHim {
    namespace Sdl {
        class Sdl {
            public:
                Sdl() = default;
                virtual ~Sdl();

                void initialize(Uint32 flags);

                // Window createWindow(const std::string& title, const Geom::Size& size);

            private:
                Sdl(const Sdl&) = delete;
                Sdl& operator=(const Sdl&) = delete;

                Sdl(Sdl&&) = delete;
                Sdl& operator=(Sdl&&) = delete;
        };
    }

    using SDL = Singleton<Sdl::Sdl>;
}

