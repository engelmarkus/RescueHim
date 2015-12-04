#pragma once

#include "State.h"

namespace RescueHim {
    class MainMenu : public State {
    public:
        using State::State;

        virtual void update() override;
        virtual void render() override;
    };
}
