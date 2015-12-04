#pragma once

#include <iosfwd>

namespace RescueHim {
    namespace Geom {
        class Size;

        /// Represents a point (resp. a vector) in 2d space.
        class Point final {
        public:
            /// Creates a new Point instance with default coordinates @f$(0; 0)@f$.
            Point() noexcept;

            /**
             * @brief Creates a new Point instance.
             * @param x The x-coordinate of the new Point.
             * @param y The y-coordinate of the new Point.
             */
            Point(int x, int y) noexcept;

            Point(Point const&) noexcept = default;
            Point& operator=(Point const&) noexcept = default;

            Point(Point&&) noexcept = default;
            Point& operator=(Point&&) noexcept = default;

            ~Point() noexcept = default;

            /**
             * @brief Creates a new Point instance out of a Size object.
             *
             * The conversion rule is as follows:
             * @arg @c width is converted to @c x.
             * @arg @c height is converted to @c y.
             *
             * @param s The Size object to be converted to a Point.
             */
            explicit Point(Size const& s) noexcept;

            Point& operator+=(Point const& p);
            Point& operator-=(Point const& p);

            /// The x-coordinate of the Point.
            int x;

            /// The y-coordinate of the Point.
            int y;
        };

        bool operator==(Point const& p1, Point const& p2);
        bool operator!=(Point const& p1, Point const& p2);

        Point operator+(Point p1, Point const& p2);
        Point operator-(Point p1, Point const& p2);

        std::ostream& operator<<(std::ostream& os, Point const& p);

        /**
         * @brief Returns the Euclidean distance between two given Points.
         */
        double length(Point const& p1, Point const& p2);
    }
}
