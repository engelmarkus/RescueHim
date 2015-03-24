#pragma once

/*namespace RescueHim {
    namespace Gui {
        class Control {
        };
    }
}
*/

#include <memory>

class Control;

namespace RescueHim {
    namespace Sdl {
        class Window;
    }
}

class Manager {
public:
    //Manager(std::shared_ptr<RescueHim::Sdl::Window> window) : window{window} {}
    Manager() {}
    
    
    Control* toplevel;
    
    
    //std::shared_ptr<RescueHim::Sdl::Window> window;
};
