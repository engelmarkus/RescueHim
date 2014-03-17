#pragma once

#include <iosfwd>

namespace RescueHim {
    namespace Geom {
        class Point;

        class Size final {
            public:
                Size() noexcept;
                Size(unsigned int w, unsigned int h) noexcept;

                Size(const Size&) noexcept = default;
                Size& operator=(const Size&) noexcept = default;

                Size(Size&&) noexcept = default;
                Size& operator=(Size&&) noexcept = default;

                ~Size() noexcept = default;

                explicit Size(const Point& p) noexcept;

                Size& operator+=(const Size& s);
                Size& operator-=(const Size& s);

                unsigned int width;
                unsigned int height;
        };

        bool operator==(const Size& s1, const Size& s2);
        bool operator!=(const Size& s1, const Size& s2);

        Size operator+(Size s1, const Size& s2);
        Size operator-(Size s1, const Size& s2);

        std::ostream& operator<<(std::ostream& os, const Size& s);
    }
}
