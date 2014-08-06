#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        struct Size_wrapper {
            /// @brief Returns a luabind class definition of Geom::Size.
            static luabind::scope getClassDefinition();
        };
    }
}
