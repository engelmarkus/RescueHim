#pragma once

#include <memory>
#include <string>

#include <lua.h>
#include <luabind/object.hpp>

namespace RescueHim {
    namespace Lua {
        class Lua final {
        public:
            using state_ptr = std::unique_ptr<lua_State, decltype(&lua_close)>;

            Lua();

            Lua(Lua const&) = delete;
            Lua(Lua&&) = default;

            Lua& operator=(Lua const&) = delete;
            Lua& operator=(Lua&&) = default;

            ~Lua() = default;

            luabind::object operator[](std::string const& key);

        private:
            state_ptr state;
        };
    }
}
