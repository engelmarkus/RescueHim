#include "Rect.h"

#include <algorithm>
#include <stdexcept>

#include <SDL_rect.h>

#include "Point.h"
#include "Size.h"

namespace RescueHim {
    namespace Geom {
        Rect::Rect(Point l, Size s) noexcept
            : location{l}, size{s}
        {
        }

        Rect::Rect(int x, int y, unsigned int w, unsigned int h) noexcept
            : location{x, y}, size{w, h}
        {
        }

        Rect::Rect(const SDL_Rect& r) noexcept
            : location{r.x, r.y}, size{static_cast<unsigned int>(r.w), static_cast<unsigned int>(r.h)}
        {
        }

        Rect::operator SDL_Rect() const {
            return SDL_Rect {
                location.x, location.y,
                static_cast<int>(size.width), static_cast<int>(size.height)
            };
        }

        Rect Rect::fromLTRB(int l, int t, int r, int b) {
            if (r < l) {
                throw std::invalid_argument{"right < left"};
            } else if (b < t) {
                throw std::invalid_argument{"bottom < top"};
            }

            return Rect {
                l, t,
                static_cast<unsigned int>(r - l), static_cast<unsigned int>(b - t)
            };
        }

        int Rect::getX() const {
            return location.x;
        }

        int Rect::getY() const {
            return location.y;
        }

        unsigned int Rect::getWidth() const {
            return size.width;
        }

        unsigned int Rect::getHeight() const {
            return size.height;
        }

        Point Rect::getLocation() const {
            return location;
        }

        Size Rect::getSize() const {
            return size;
        }

        int Rect::getLeft() const {
            return location.x;
        }

        int Rect::getTop() const {
            return location.y;
        }

        int Rect::getBottom() const {
            return location.y + size.height;
        }

        int Rect::getRight() const {
            return location.x + size.width;
        }

        void Rect::offsetBy(const Point& p) {
            location += p;
        }

        bool Rect::contains(const Point& p) const {
            return (p.x >= getLeft() && p.x <= getRight()) && (p.y >= getTop() && p.y <= getBottom());
        }

        bool Rect::contains(const Rect& r) const {
            return (this->contains(r.location) && this->contains(r.location + static_cast<Point>(r.size)));
        }

        bool Rect::intersectsWith(const Rect& r) const {
            if (this->getRight() <= r.getLeft() || r.getRight() <= this->getLeft()) {
                return false;
            }

            if (this->getBottom() <= r.getTop() || r.getBottom() <= this->getTop()) {
                return false;
            }

            return true;
        }

        Rect Rect::intersectWith(const Rect& r) const {
            if (!this->intersectsWith(r)) {
                return Rect { 0, 0, 0, 0 };
            }

            return Rect::fromLTRB(
                std::max(this->getLeft(), r.getLeft()), 
                std::max(this->getTop(), r.getTop()), 
                std::min(this->getRight(), r.getRight()), 
                std::min(this->getBottom(), r.getBottom())
            );
        }

        bool operator==(const Rect& r1, const Rect& r2) {
            return (r1.location == r2.location) && (r1.size == r2.size);
        }

        bool operator!=(const Rect& r1, const Rect& r2) {
            return !(r1 == r2);
        }
    }
}
