#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        class Rect_wrapper {
            public:
                /// @brief Returns a luabind class definition of Geom::Rect.
                static luabind::scope getClassDefinition();
        };
    }
}
