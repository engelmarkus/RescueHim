#pragma once

#include <iosfwd>

namespace RescueHim {
    namespace Geom {
        class Point;
	/// Represents the Size of a rectangle.
        class Size final {
            public:
		/// Creates a new Size instance with default width and height equal to 0.
                Size() noexcept;
		/*
		 * @brief Creates a new Size instance
		 * @param w The width
		 * @param h The weight
		 **/
                Size(unsigned int w, unsigned int h) noexcept;
		/// Creates a new Size instance from an existing one.
                Size(const Size&) noexcept = default;
                Size& operator=(const Size&) noexcept = default;

                Size(Size&&) noexcept = default;
                Size& operator=(Size&&) noexcept = default;

                ~Size() noexcept = default;

                explicit Size(const Point& p) noexcept;
		
                Size& operator+=(const Size& s);
                Size& operator-=(const Size& s);
		/// The width
                unsigned int width;
		/// The height
                unsigned int height;
        };

        bool operator==(const Size& s1, const Size& s2);
        bool operator!=(const Size& s1, const Size& s2);

        Size operator+(Size s1, const Size& s2);
        Size operator-(Size s1, const Size& s2);

        std::ostream& operator<<(std::ostream& os, const Size& s);
    }
}
