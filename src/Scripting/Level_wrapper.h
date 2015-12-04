#pragma once

#include <luabind/scope.hpp>
#include <luabind/wrapper_base.hpp>

#include "Level.h"

namespace RescueHim {
    namespace Lua {
        struct Level_wrapper : Level, luabind::wrap_base {
            Level_wrapper();

            virtual void onStart();

            static void default_onStart(Level* ptr);

            /// @brief Returns a luabind class definition of Level.
            static luabind::scope getClassDefinition();
        };
    }
}
