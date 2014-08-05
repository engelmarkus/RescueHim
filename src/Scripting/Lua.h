#pragma once

#include <string>

//extern "C" {
    #include <lua.h>
    #include <lualib.h>
//}

#include <luabind/luabind.hpp>

namespace RescueHim {
    namespace Lua {
        class Lua final {
            public:
                typedef std::unique_ptr<lua_State, decltype(&lua_close)> state_ptr;
                
                Lua();
                
                Lua(const Lua&) = delete;
                Lua(Lua&&) = default;
                
                Lua& operator=(const Lua&) = delete;
                Lua& operator=(Lua&&) = default;

                ~Lua() = default;
                
                luabind::object operator[](const std::string& key);
                
            private:
                state_ptr state;
        };
    }
}
