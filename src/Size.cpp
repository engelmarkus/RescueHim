#include "Size.h"

#include <ostream>
#include "Point.h"

namespace RescueHim {
    namespace Geom {
        Size::Size()
            : width{0}, height{0}
        {
        }

        Size::Size(unsigned int w, unsigned int h) 
            : width{w}, height{h}
        {
        }

        Size::Size(const Point& p)
            : width{static_cast<unsigned int>(p.x)}, height{static_cast<unsigned int>(p.y)}
        {
        }

        void Size::operator+=(const Size& s) {
            this->width += s.width;
            this->height += s.height;
        }

        void Size::operator-=(const Size& s) {
            this->width -= s.width;
            this->height -= s.height;
        }


        bool operator==(const Size& s1, const Size& s2) {
            return (s1.width == s2.width) && (s1.height == s2.height);
        }

        bool operator!=(const Size& s1, const Size& s2) {
            return !(s1 == s2);
        }

        Size operator+(const Size& s1, const Size& s2) {
            return Size{s1.width + s2.width, s1.height + s2.height};
        }

        Size operator-(const Size& s1, const Size& s2) {
            return Size{s1.width - s2.width, s1.height - s2.height};
        }

        std::ostream& operator<<(std::ostream& os, const Size& s) {
            os << s.width << "x" << s.height;

            return os;
        }
    }
}

