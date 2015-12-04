#include "Rect_wrapper.h"

#include <functional>

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>

#include "Point.h"
#include "Rect.h"
#include "Scripting/ScopeFactory.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Rect", &Rect_wrapper::getClassDefinition);
        }

        luabind::scope Rect_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Geom;

            return (
                class_<Rect>("Rect")
                    .def(constructor<Point, Size>())
                    .def(constructor<int, int, unsigned int, unsigned int>())
                    .def(constructor<Rect const&>())

                    .scope [
                        def("fromLTRB", &Rect::fromLTRB)
                    ]

                    .property("X", &Rect::getX)
                    .property("Y", &Rect::getY)

                    .property("Width", &Rect::getWidth)
                    .property("Height", &Rect::getHeight)

                    .property("Location", &Rect::getLocation)
                    .property("Size", &Rect::getSize)

                    .property("Top", &Rect::getTop)
                    .property("Left", &Rect::getLeft)
                    .property("Right", &Rect::getRight)
                    .property("Bottom", &Rect::getBottom)

                    .def("offsetBy", &Rect::offsetBy)

                    .def("containsPoint", (bool(Rect::*)(Point const&) const)&Rect::contains)
                    .def("containsRect", (bool(Rect::*)(Rect const&) const)&Rect::contains)

                    // schön wenns so ginge.
                    //.def("containsPoint", std::mem_fn<bool(const Point&) const>(&Rect::contains))

                    .def("intersectsWith", &Rect::intersectsWith)
                    .def("intersectWith", &Rect::intersectWith)

                    .def(const_self == other<Rect const&>())
            );
        }
    }
}
