#include "Size_wrapper.h"

#include <utility>

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

#include "Scripting/ScopeFactory.h"
#include "Size.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Size", &Size_wrapper::getClassDefinition);
        }

        luabind::scope Size_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Geom;

            return (
                class_<Size>("Size")
                    .def(constructor<>())
                    .def(constructor<int, int>())
                    .def(constructor<Size const&>())

                    .def_readwrite("width", &Size::width)
                    .def_readwrite("height", &Size::height)

                    .def(const_self + other<Size const&>())
                    .def(const_self - other<Size const&>())
                    .def(const_self == other<Size const&>())
            );
        }
    }
}
