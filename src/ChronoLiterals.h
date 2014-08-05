#pragma once

#include <chrono>

namespace std {
    inline namespace literals {
        inline namespace chrono_literals {
    
            constexpr chrono::milliseconds operator "" ms(unsigned long long c) {
                return chrono::milliseconds{c};
            }
            
        }
    }
}
