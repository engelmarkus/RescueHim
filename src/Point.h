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

                Point(const Point&) noexcept = default;
                Point& operator=(const Point&) noexcept = default;

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
                explicit Point(const Size& s) noexcept;

                Point& operator+=(const Point& p);
                Point& operator-=(const Point& p);

                /// The x-coordinate of the Point.
                int x;

                /// The y-coordinate of the Point.
                int y;
        };

        bool operator==(const Point& p1, const Point& p2);
        bool operator!=(const Point& p1, const Point& p2);

        Point operator+(Point p1, const Point& p2);
        Point operator-(Point p1, const Point& p2);

        std::ostream& operator<<(std::ostream& os, const Point& p);
        
        /**
         * @brief Returns the Euclidean distance between two given Points.
         */
        double length(const Point& p1, const Point& p2);
    }
}
