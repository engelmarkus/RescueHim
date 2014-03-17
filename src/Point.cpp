#include "Point.h"

#include <ostream>

#include "Size.h"

namespace RescueHim {
    namespace Geom {
        Point::Point() noexcept
            : x{0}, y{0}
        {
        }

        Point::Point(int x, int y) noexcept
            : x{x}, y{y}
        {
        }

        Point::Point(const Size& s) noexcept
            : x{static_cast<int>(s.width)}, y{static_cast<int>(s.height)}
        {
        }

        Point& Point::operator+=(const Point& p) {
            this->x += p.x;
            this->y += p.y;
            
            return *this;
        }

        Point& Point::operator-=(const Point& p) {
            this->x -= p.x;
            this->y -= p.y;
            
            return *this;
        }


        bool operator==(const Point& p1, const Point& p2) {
            return (p1.x == p2.x) && (p1.y == p2.y);
        }

        bool operator!=(const Point& p1, const Point& p2) {
            return !(p1 == p2);
        }

        Point operator+(Point p1, const Point& p2) {
            p1 += p2;

            return p1;
        }

        Point operator-(Point p1, const Point& p2) {
            p1 -= p2;

            return p1;
        }

        std::ostream& operator<<(std::ostream& os, const Point& p) {
            os << "(" << p.x << "; " << p.y << ")";

            return os;
        }
    }
}
