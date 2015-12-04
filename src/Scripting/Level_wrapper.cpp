#include "Level_wrapper.h"

#include <string>
#include <utility>

#include <luabind/luabind.hpp>

#include "Level.h"
#include "Scripting/ScopeFactory.h"
#include "Size.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Level", &Level_wrapper::getClassDefinition);
        }

        Level_wrapper::Level_wrapper()
            : Level()
        {
        }

        void Level_wrapper::onStart() {
            call<void>("OnStart");
        }

        void Level_wrapper::default_onStart(Level*) {
            throw;
        }

        luabind::scope Level_wrapper::getClassDefinition() {
            using namespace luabind;

            return (
                class_<Level, no_bases, default_holder, Level_wrapper>("Level")
                    .def(constructor<>())
                    .def_readwrite("Name", &Level::Name)
                    .def_readwrite("Size", &Level::Size)
                    .def_readwrite("Map", &Level::Map)
                    .def_readwrite("Enemies", &Level::Enemies)

                    .def("OnStart", &Level::onStart, &Level_wrapper::default_onStart)
            );
        }
    }
}
