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
            Size(Size const&) noexcept = default;

            Size& operator=(Size const&) noexcept = default;

            Size(Size&&) noexcept = default;
            Size& operator=(Size&&) noexcept = default;

            ~Size() noexcept = default;

            explicit Size(Point const& p) noexcept;

            Size& operator+=(Size const& s);
            Size& operator-=(Size const& s);

            /// The width
            unsigned int width;

            /// The height
            unsigned int height;
        };

        bool operator==(Size const& s1, Size const& s2);
        bool operator!=(Size const& s1, Size const& s2);

        Size operator+(Size s1, Size const& s2);
        Size operator-(Size s1, Size const& s2);

        std::ostream& operator<<(std::ostream& os, Size const& s);
    }
}
