#include "types.h"

#include <float.h>

NS_CC_BEGIN

// implementation of Size

Size::Size() : width(0), height(0)
{
}

Size::Size(float w, float h) : width(w), height(h)
{
}

Size::Size(const Size& other) : width(other.width), height(other.height)
{
}

Size& Size::operator= (const Size& other)
{
    setSize(other.width, other.height);
    return *this;
}

Size Size::operator+(const Size& right) const
{
    return Size(this->width + right.width, this->height + right.height);
}

Size Size::operator-(const Size& right) const
{
    return Size(this->width - right.width, this->height - right.height);
}

Size Size::operator*(float a) const
{
    return Size(this->width * a, this->height * a);
}

Size Size::operator/(float a) const
{
    CCASSERT(a!=0, "CCSize division by 0.");
    return Size(this->width / a, this->height / a);
}

void Size::setSize(float w, float h)
{
    this->width = w;
    this->height = h;
}

bool Size::equals(const Size& target) const
{
    return (std::abs(this->width  - target.width)  < FLT_EPSILON)
    && (std::abs(this->height - target.height) < FLT_EPSILON);
}

const Size Size::ZERO = Size(0, 0);


NS_CC_END
