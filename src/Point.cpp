#include "Point.h"

#include "Size.h"

namespace RescueHim {
	namespace Geom {
		Point::Point()
			: x(0), y(0)
		{
		}

		Point::Point(int x, int y)
			: x(x), y(y)
		{
		}

		Point::Point(const Point& p) 
			: x(p.x), y(p.y)
		{
		}

		Point& Point::operator=(const Point& p) {
			this->x = p.x;
			this->y = p.y;

			return *this;
		}

		Point::Point(const Size& s)
			: x(s.width), y(s.height)
		{
		}

		void Point::operator+=(const Point& p) {
			this->x += p.x;
			this->y += p.y;
		}

		void Point::operator-=(const Point& p) {
			this->x -= p.x;
			this->y -= p.y;
		}


		bool operator==(const Point& p1, const Point& p2) {
			return (p1.x == p2.x) && (p1.y == p2.y);
		}

		bool operator!=(const Point& p1, const Point& p2) {
			return !(p1 == p2);
		}

		Point operator+(const Point& p1, const Point& p2) {
			return Point(p1.x + p2.x, p1.y + p2.y);
		}

		Point operator-(const Point& p1, const Point& p2) {
			return Point(p1.x - p2.x, p1.y - p2.y);
		}

		std::ostream& operator<<(std::ostream& os, const Point& p) {
			os << "(" << p.x << "; " << p.y << ")";

			return os;
		}
	}
}

