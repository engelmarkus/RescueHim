#pragma once

#include <algorithm>
#include <memory>

#include <sigc++/connection.h>

#include "State.h"

namespace RescueHim {
    class MainWindow;

    class Game {
    public:
        void initialize();

        MainWindow& getMainWindow();

        void update();
        void render();

        template<typename State, typename... Args>
        void switchState(Args&&... args) {
            currentState = std::make_unique<State>(std::forward<Args>(args)...);
        }

    private:
        std::shared_ptr<MainWindow> mainWindow;
        std::unique_ptr<State> currentState;

        sigc::connection updateConnection;
        sigc::connection renderConnection;
    };
}
