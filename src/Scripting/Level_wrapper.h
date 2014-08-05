#pragma once

#include <luabind/luabind.hpp>
#include "../Level.h"

namespace RescueHim {
    namespace Lua {
        struct Level_wrapper : Level, luabind::wrap_base {
            Level_wrapper();

            virtual void onStart();

            static void default_onStart(Level* ptr);

            static luabind::scope getClassDefinition();
        };
    }
}
