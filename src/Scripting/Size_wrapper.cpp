#include "Size_wrapper.h"

#include <luabind/operator.hpp>
#include "../Size.h"

namespace RescueHim {
    namespace Lua {
        luabind::scope Size_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Geom;

            return (
                class_<Size>("Size")
                    .def(constructor<>())
                    .def(constructor<int, int>())
                    .def(constructor<const Size&>())

                    .def_readwrite("width", &Size::width)
                    .def_readwrite("height", &Size::height)

                    .def(const_self + other<const Size&>())
                    .def(const_self - other<const Size&>())
                    .def(const_self == other<const Size&>())
            );
        }
    }
}
