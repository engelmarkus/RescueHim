#pragma once

#include <iosfwd>

namespace RescueHim {
    namespace Geom {
        class Point;

        class Size final {
            public:
                Size();
                Size(unsigned int w, unsigned int h);

                Size(const Size&) = default;
                Size& operator=(const Size&) = default;

                Size(Size&&) noexcept = default;
                Size& operator=(Size&&) = default;

                ~Size() = default;

                explicit Size(const Point& p);

                void operator+=(const Size& s);
                void operator-=(const Size& s);

                unsigned int width;
                unsigned int height;
        };

        bool operator==(const Size& s1, const Size& s2);
        bool operator!=(const Size& s1, const Size& s2);

        Size operator+(const Size& s1, const Size& s2);
        Size operator-(const Size& s1, const Size& s2);

        std::ostream& operator<<(std::ostream& os, const Size& s);
    }
}

