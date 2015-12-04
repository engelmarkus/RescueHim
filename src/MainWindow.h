#pragma once

#include "Window.h"
#include "Gui.h"

namespace RescueHim {
    namespace Geom {
        class Point;
    }

    class MainWindow : public Sdl::Window {
    public:
        MainWindow();

        virtual void onMouseMove(Geom::Point position) override;

        Manager m;
    };
}
