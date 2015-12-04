#include "Point.h"

#include <cmath>
#include <ostream>

#include "Size.h"

namespace RescueHim {
    namespace Geom {
        Point::Point() noexcept
            : x{0}
            , y{0}
        {
        }

        Point::Point(int x, int y) noexcept
            : x{x}
            , y{y}
        {
        }

        Point::Point(Size const& s) noexcept
            : x{static_cast<int>(s.width)}
            , y{static_cast<int>(s.height)}
        {
        }

        Point& Point::operator+=(Point const& p) {
            this->x += p.x;
            this->y += p.y;

            return *this;
        }

        Point& Point::operator-=(Point const& p) {
            this->x -= p.x;
            this->y -= p.y;

            return *this;
        }


        bool operator==(Point const& p1, Point const& p2) {
            return (p1.x == p2.x) && (p1.y == p2.y);
        }

        bool operator!=(Point const& p1, Point const& p2) {
            return !(p1 == p2);
        }

        Point operator+(Point p1, Point const& p2) {
            p1 += p2;

            return p1;
        }

        Point operator-(Point p1, Point const& p2) {
            p1 -= p2;

            return p1;
        }

        std::ostream& operator<<(std::ostream& os, Point const& p) {
            os << "(" << p.x << "; " << p.y << ")";

            return os;
        }

        double length(Point const& p1, Point const& p2) {
            auto diff = p2 - p1;

            return std::sqrt(diff.x * diff.x + diff.y * diff.y);
        }
    }
}
