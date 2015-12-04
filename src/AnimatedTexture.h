#pragma once

#include <chrono>

#include "Rect.h"
#include "Renderer.h"
#include "Size.h"
#include "Surface.h"
#include "Texture.h"

namespace RescueHim {
    namespace Geom {
        class Point;
    }

    namespace Sdl {
        class AnimatedTexture : public Texture {
        public:
            using clock = std::chrono::steady_clock;

            AnimatedTexture() = delete;
            AnimatedTexture(Renderer const& renderer, Surface const& surface, Geom::Size frameSize, int numFrames, clock::duration frameDuration);

            virtual ~AnimatedTexture() = default;

            virtual Geom::Size getSize() const override;

            //virtual void draw(const Renderer& renderer, Geom::Point dest) override;
            virtual void draw(Geom::Point dest) override;

        private:
            Geom::Size frameSize;
            int numFrames;
            clock::duration frameDuration;

            int currentFrame;
            Geom::Rect currentRect;
            clock::time_point lastTime;
        };
    }
}
