#pragma once

#include <stdexcept>

namespace RescueHim {
    namespace Sdl {
        class SdlError : public std::runtime_error {
            using std::runtime_error::runtime_error;
        };
    }
}

