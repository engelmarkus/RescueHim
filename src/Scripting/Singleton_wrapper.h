#pragma once

#include <luabind/luabind.hpp>

#include "Image.h"
#include "Singleton.h"

namespace RescueHim {
    namespace Lua {
        template <char const* Name, typename T>
        class Singleton_wrapper {
        public:
            static luabind::scope getClassDefinition() {
                using namespace luabind;

                return (
                    class_<Singleton<T>>(Name)
                        .def("instance", &Singleton<T>::instance)
                );
            }
        };

        class Image_wrapper {
        public:
            static luabind::scope getClassDefinition() {
                using namespace luabind;

                return (
                    class_<Sdl::Image>("Image")
                        .def("load", &Sdl::Image::load)
                );
            }
        };
    }
}
