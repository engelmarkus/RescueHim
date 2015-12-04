#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        class Player_wrapper {
        public:
            /// @brief Returns a luabind class definition of Player.
            static luabind::scope getClassDefinition(); 
        };
    }
}
