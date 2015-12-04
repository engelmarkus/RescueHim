#pragma once

#include "Factory.h"
#include "Singleton.h"

namespace luabind {
    struct scope;
}

namespace RescueHim {
    namespace Lua {
        using ScopeFactory = Singleton<Factory<luabind::scope>>;
    }
}
