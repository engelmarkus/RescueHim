#pragma once

#include <luabind/luabind.hpp>

namespace RescueHim {
    namespace Lua {
        struct Size_wrapper {
            static luabind::scope getClassDefinition();
        };
    }
}
