#include "Lua.h"

#include <iostream>
#include <memory>

#include <lauxlib.h>
#include <lualib.h>
#include <luabind/luabind.hpp>
#include <luabind/adopt_policy.hpp>

#include "../Point.h"
#include "../Size.h"
#include "../Level.h"
#include "Level_wrapper.h"
#include "Point_wrapper.h"
#include "Size_wrapper.h"

namespace std {
luabind::iterator begin(luabind::adl::object& table) {
    return luabind::iterator(table);
}

luabind::iterator end(luabind::object&) {
    return luabind::iterator{};
}
}

namespace RescueHim {
    namespace Lua {
        Lua::Lua()
            : state{luaL_newstate(), lua_close}
        {
            using namespace luabind;

            // Bind the new state to luabind.
            open(state.get());

            // Load Lua's default libraries.
            luaL_openlibs(state.get());

            // Register wrappers for some C++ classes.
            module(state.get()) [
                Point_wrapper::getClassDefinition(),
                Size_wrapper::getClassDefinition(),
                Level_wrapper::getClassDefinition()
            ];

            // Load some convenience functions for later use.
            luaL_dofile(state.get(), "../data/scripts/internal.lua");

            try {
                //bool errors = luaL_dofile(state.get(), "../data/scripts/level.lua");

                // Man kann lua auch als c++ kompilieren, sodass es statt
                // der fehlercodes direkt exceptions wirft...
                // luabind::error ist eigentlich eh nicht die richtige.
                //if (errors) {
                //    throw luabind::error{state.get()};
                //}
                
                bool errors = luaL_loadfile(state.get(), "../data/scripts/level.lua");
                
                if (errors) {
                    throw luabind::error{state.get()};
                }
                
                luabind::object script(luabind::from_stack(state.get(), -1));
                luabind::call_function<void>(script);
                
                lua_pop(state.get(), 1);

                // Einen Zeiger auf die Klasse (!) holen
                auto klasse = (*this)["DasLevel"];
                
                // Ein Objekt davon konstruieren und das ownership an den unique_ptr übertragen.
                auto level = std::unique_ptr<Level>(object_cast<Level*>(klasse(), adopt(result)));
                
                level->onStart();
                
                // über die enemies-table iterieren
                for (auto i : level->Enemies) {
                    std::cout << object_cast<Geom::Point>(i) << std::endl;
                }

                
                                
            } catch(const luabind::error& error) {
                std::cout << lua_tostring(error.state(), -1) << std::endl;
            }
        }

        luabind::object Lua::operator[](const std::string& key) {
            return luabind::globals(state.get())[key];
        }
    }
}
