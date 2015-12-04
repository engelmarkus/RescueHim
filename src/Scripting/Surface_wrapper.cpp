#include "Surface_wrapper.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

#include "Scripting/ScopeFactory.h"
#include "Size.h"
#include "Surface.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Surface", &Surface_wrapper::getClassDefinition);
        }

        luabind::scope Surface_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Sdl;

            return (
                class_<Surface>("Surface")
                    .def(constructor<Geom::Size const&, uint8_t, uint8_t, uint8_t, uint8_t>())
                    .def(constructor<Surface const&>())

                    .property("width", &Surface::getWidth)
                    .property("height", &Surface::getHeight)
                    .property("size", &Surface::getSize)
                    .property("mustLock", &Surface::mustLock)
            );
        }
    }
}
