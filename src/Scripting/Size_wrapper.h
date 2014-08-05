#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        struct Size_wrapper {
            static luabind::scope getClassDefinition();
        };
    }
}
