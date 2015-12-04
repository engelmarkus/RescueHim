#include "Point_wrapper.h"

#include <utility>

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

#include "Point.h"
#include "Scripting/ScopeFactory.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Point", &Point_wrapper::getClassDefinition);
        }

        luabind::scope Point_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Geom;

            return (
                class_<Point>("Point")
                    .def(constructor<>())
                    .def(constructor<int, int>())
                    .def(constructor<Point const&>())

                    .def_readwrite("x", &Point::x)
                    .def_readwrite("y", &Point::y)

                    .def(const_self + other<Point const&>())
                    .def(const_self - other<Point const&>())
                    .def(const_self == other<Point const&>())

                    .scope [
                        def("length", &length)
                    ]

            );
        }
    }
}
