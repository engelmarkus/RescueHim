#include "MainWindow.h"

#include "Point.h"
#include "Size.h"

namespace RescueHim {
    using namespace Geom;
    using namespace Sdl;
    
    MainWindow::MainWindow()
        : Window("Hauptfenster", Point{100, 100}, Size{640, 480})
    {
    }
}
