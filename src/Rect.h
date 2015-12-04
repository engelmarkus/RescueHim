#pragma once

#include "Point.h"
#include "Size.h"

struct SDL_Rect;

namespace RescueHim {
    namespace Geom {
        /// Represents a rectangle in 2d space.
        class Rect final {
        public:
            /**
             * @brief Creates a new Rect instance.
             * @param l The location of the top-left corner.
             * @param s The size of the new Rect.
             */
            Rect(Point l, Size s) noexcept;

            /**
             * @brief Creates a new Rect instance.
             * @param x The x-coordinate.
             * @param y The y-coordinate.
             * @param w The width.
             * @param h The height.
             */
            Rect(int x, int y, unsigned int w, unsigned int h) noexcept;

            /// @brief Creates a new Rect instance from an existing SDL_Rect.
            Rect(SDL_Rect const& r) noexcept;

            Rect(Rect const&) noexcept = default;
            Rect& operator=(Rect const&) noexcept = default;

            Rect(Rect&&) noexcept = default;
            Rect& operator=(Rect&&) noexcept = default;

            ~Rect() noexcept = default;

            /// @brief Converts a Rect object into an SDL_Rect.
            operator SDL_Rect() const;

            /**
             * @brief Creates a Rect out of the locations of the four borders.
             * @param l The x-coordinate of the left border.
             * @param t The y-coordinate of the top border.
             * @param r The x-coordinate of the right border.
             * @param b The y-coordinate of the bottom border.
             * @returns The newly created Rect with #location and #size set appropriately.
             * @throws std::invalid_argument If @p r is less than @p l.
             * @throws std::invalid_argument If @p b is less than @p t.
             */
            static Rect fromLTRB(int l, int t, int r, int b);

            /// @returns The x-coordinate of the top-left corner.
            int getX() const;

            /// @returns The y-coordinate of the top-left corner.
            int getY() const;

            /// @returns The width.
            unsigned int getWidth() const;

            /// @returns The height.
            unsigned int getHeight() const;

            /// @returns The location of the top-left corner.
            Point getLocation() const;

            /// @returns The size.
            Size getSize() const;

            /// @returns The y-coordinate of the upper border.
            int getTop() const;

            /// @returns The x-coordinate of the left border.
            int getLeft() const;

            /// @returns The y-coordinate of the lower border.
            int getBottom() const;

            /// @returns The x-coordinate of the right border.
            int getRight() const;

            /**
             * @brief Moves the Rect relatively according to the passed Point.
             * @param p The point (vector) that describes the move.
             */
            void offsetBy(Point const& p);

            /**
             * @brief Determines whether a Point is contained in a Rect.
             * @param p The Point to check.
             * @retval true The Point lies inside the Rect.
             * @retval false The Point is outside the Rect.
             */
            bool contains(Point const& p) const;

            /**
             * @brief Determines whether a Rect is contained in the current Rect.
             * @param r The Rect to check.
             * @retval true The Rect lies completely inside the current Rect.
             * @retval false The Rect is (at least partly) outside the current Rect.
             */
            bool contains(Rect const& r) const;

            /**
             * @brief Checks whether this Rect and another Rect intersect each other.
             * @param r The second Rect to check.
             * @retval true The two Rects overlap.
             * @retval false The two Rects do not have any common area.
             */
            bool intersectsWith(Rect const& r) const;

            /**
             * @brief Calculates a Rect representing the intersection of this Rect and another.
             * @param r The second Rect.
             * @returns A new Rect with the common area. If the Rects do not intersect each other,
             * @c Rect(0, 0, 0, 0) is returned, i. e. an empty Rect.
             */
            Rect intersectWith(Rect const& r) const;

        private:
            /// The location of the top-left corner.
            Point location;

            /// The size of the Rect.
            Size size;

            friend bool operator==(Rect const& r1, Rect const& r2);
            friend bool operator!=(Rect const& r1, Rect const& r2);
        };
    }
}
