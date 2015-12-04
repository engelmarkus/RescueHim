#include "Player_wrapper.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

#include "Player.h"
#include "Point.h"
#include "Scripting/ScopeFactory.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Player", &Player_wrapper::getClassDefinition);
        }

        luabind::scope Player_wrapper::getClassDefinition() {
            using namespace luabind;

            return (
                luabind::class_<Player>("Player")
                    .def(constructor<int, int>())
                    .def(constructor<Geom::Point>())
                    .def(constructor<Player const&>())

                    .property("position", &Player::getPosition)

                    .def("moveTop", &Player::moveTop)
                    .def("moveDown", &Player::moveDown)
                    .def("moveLeft", &Player::moveLeft)
                    .def("moveRight", &Player::moveRight)
            );
        }
    }
}
