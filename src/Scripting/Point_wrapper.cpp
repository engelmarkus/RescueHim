#include "Point_wrapper.h"

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>
#include "../Point.h"

namespace RescueHim {
    namespace Lua {
        luabind::scope Point_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Geom;
            
            return (
                class_<Point>("Point")
                    .def(constructor<>())
                    .def(constructor<int, int>())
                    .def(constructor<const Point&>())

                    .def_readwrite("x", &Point::x)
                    .def_readwrite("y", &Point::y)

                    .def(const_self + other<const Point&>())
                    .def(const_self - other<const Point&>())
                    .def(const_self == other<const Point&>())
                    
                    .scope [
                        def("length", &length)
                    ]
                
            );
        }
    }
}
