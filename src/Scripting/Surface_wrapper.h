#pragma once

#include <luabind/scope.hpp>

namespace RescueHim {
    namespace Lua {
        class Surface_wrapper {
        public:
            static luabind::scope getClassDefinition();
        };
    }
}
