#pragma once

#include <luabind/scope.hpp>
#include <luabind/wrapper_base.hpp>

#include "Window.h"

namespace RescueHim {
    namespace Lua {
        class Window_wrapper : public Sdl::Window, luabind::wrap_base {
        public:
            Window_wrapper() = default;

            //        virtual void onShown();
            //        static void default_onShown(Sdl::Window* wnd);

            static luabind::scope getClassDefinition();
        };
    }
}
