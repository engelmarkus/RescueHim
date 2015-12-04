#pragma once

namespace RescueHim {
    class Game;

    class State {
    public:
        State(Game& game) : game(game) {}
        virtual ~State() {}

        virtual void update() = 0;
        virtual void render() = 0;

    protected:
        Game& game;
    };
}
