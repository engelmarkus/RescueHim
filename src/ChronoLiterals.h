#pragma once

#include <chrono>

// These literals are about to be added to std::chrono_literals in c++14...

/**
 * @brief Literal to ease notation of durations taking milliseconds.
 * @details Example Usage:
 * @code
 * std::chrono::duration half_a_second = 500_ms;
 * @endcode
 * @see std::chrono::duration
 */
constexpr std::chrono::milliseconds operator "" _ms(unsigned long long c) {
    return std::chrono::milliseconds{c};
}

