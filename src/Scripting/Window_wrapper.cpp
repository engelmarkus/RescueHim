#include "Window_wrapper.h"

#include <luabind/luabind.hpp>

#include "Scripting/ScopeFactory.h"
#include "Window.h"

namespace RescueHim {
    namespace Lua {
        namespace {
            bool registered = ScopeFactory::instance().registerObject("Window", &Window_wrapper::getClassDefinition);
        }

        luabind::scope Window_wrapper::getClassDefinition() {
            using namespace luabind;
            using namespace Sdl;

            return (
                class_<Window>("Window")
                    .def(constructor<std::string const&, Geom::Point const&, Geom::Size const&>())

                    .property("id", &Window::getId)
                    .property("title", &Window::getTitle, &Window::setTitle)
                    .property("size", &Window::getSize, &Window::setSize)
                    .property("position", &Window::getPosition, &Window::setPosition)

                    .def("hide", &Window::hide)
                    .def("maximize", &Window::maximize)
                    .def("minimize", &Window::minimize)
                    .def("raise", &Window::raise)
                    .def("restore", &Window::restore)
                    .def("show", &Window::show)

                    .def("onShown", &Window::onShown)
            );
        }
    }
}
