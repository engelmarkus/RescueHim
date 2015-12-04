#pragma once

#include <memory>
#include "State.h"
#include "Surface.h"
#include "Texture.h"

namespace RescueHim {
    class Game;

    class Intro : public State {
    public:
        Intro(Game& game);

        virtual void update() override;
        virtual void render() override;

        int counter;

        Sdl::Surface logoNormal;
        Sdl::Surface logoGlow;

        std::unique_ptr<Sdl::Texture> normalTexture, glowTexture;
    };
}
