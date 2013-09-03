#pragma once

#include <ostream>

namespace RescueHim {
	namespace Geom {
		class Point;

		class Size final {
			public:
				Size();
				Size(unsigned int w, unsigned int h);
				Size(const Size& s);
				Size& operator=(const Size& s);
				~Size() = default;

				explicit Size(const Point& p);

				void operator+=(const Size& s);
				void operator-=(const Size& s);

				unsigned int width, height;
		};

		bool operator==(const Size& s1, const Size& s2);
		bool operator!=(const Size& s1, const Size& s2);

		Size operator+(const Size& s1, const Size& s2);
		Size operator-(const Size& s1, const Size& s2);

		std::ostream& operator<<(std::ostream& os, const Size& s);
	}
}

