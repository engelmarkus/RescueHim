#pragma once

#include <ostream>

namespace RescueHim {
	namespace Geom {
		class Size;

		class Point final {
			public:
				Point();
				Point(int x, int y);
				Point(const Point& p);
				Point& operator=(const Point& p);
				~Point() = default;

				explicit Point(const Size& s);

				void operator+=(const Point& p);
				void operator-=(const Point& p);

				int x, y;
		};

		bool operator==(const Point& p1, const Point& p2);
		bool operator!=(const Point& p1, const Point& p2);

		Point operator+(const Point& p1, const Point& p2);
		Point operator-(const Point& p1, const Point& p2);

		std::ostream& operator<<(std::ostream& os, const Point& p);
	}
}
