#pragma once

#include "Point.h"
#include "Size.h"

namespace RescueHim {
	namespace Geom {
		class Rect final {
			public:
				Rect(const Point& l, const Size& s);
				Rect(int x, int y, unsigned int w, unsigned int h);
				Rect(const Rect& r);
				Rect& operator=(const Rect& r);
				~Rect() = default;

				static Rect fromLTRB(int l, int t, int r, int b);

				int getX() const;
				int getY() const;
				int getWidth() const;
				int getHeight() const;
				const Point& getLocation() const;
				const Size& getSize() const;
				int getTop() const;
				int getLeft() const;
				int getBottom() const;
				int getRight() const;

				void offsetBy(const Point& p);

				bool contains(const Point& p) const;
				bool contains(const Rect& r) const;

				bool intersectsWith(const Rect& r) const;

				Rect intersectWith(const Rect& r) const;

			private:
				Point location;
				Size size;

				friend bool operator==(const Rect& r1, const Rect& r2);
				friend bool operator!=(const Rect& r1, const Rect& r2);
		};

		bool operator==(const Rect& r1, const Rect& r2);
		bool operator!=(const Rect& r1, const Rect& r2);
	}
}

