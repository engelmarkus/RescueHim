#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        class Point_wrapper {
            public:
                /// @brief Returns a luabind class definition of Geom::Point.
                static luabind::scope getClassDefinition();
        };
    }
}
