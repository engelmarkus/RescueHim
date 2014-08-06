#pragma once

#include <luabind/object.hpp>

namespace luabind {
    namespace adl {
        iterator begin(object& table) {
            return iterator{table};
        }

        iterator end(object&) {
            return iterator{};
        }
    }
}
