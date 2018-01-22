#include "types.h"

NS_CC_GFX_BEGIN

const char* ATTRIB_NAME_POSITION = "a_position";
const char* ATTRIB_NAME_NORMAL = "a_normal";
const char* ATTRIB_NAME_TANGENT = "a_tangent";
const char* ATTRIB_NAME_BITANGENT = "a_bitangent";
const char* ATTRIB_NAME_WEIGHTS = "a_weights";
const char* ATTRIB_NAME_JOINTS = "a_joints";
const char* ATTRIB_NAME_COLOR = "a_color";
const char* ATTRIB_NAME_COLOR0 = "a_color0";
const char* ATTRIB_NAME_COLOR1 = "a_color1";
const char* ATTRIB_NAME_UV = "a_uv";
const char* ATTRIB_NAME_UV0 = "a_uv0";
const char* ATTRIB_NAME_UV1 = "a_uv1";
const char* ATTRIB_NAME_UV2 = "a_uv2";
const char* ATTRIB_NAME_UV3 = "a_uv3";
const char* ATTRIB_NAME_UV4 = "a_uv4";
const char* ATTRIB_NAME_UV5 = "a_uv5";
const char* ATTRIB_NAME_UV6 = "a_uv6";
const char* ATTRIB_NAME_UV7 = "a_uv7";

NS_CC_GFX_END

NS_CC_BEGIN

/**
 * Color4F
 */

Color4F::Color4F()
: r(0.0f)
, g(0.0f)
, b(0.0f)
, a(0.0f)
{}

Color4F::Color4F(float _r, float _g, float _b, float _a)
: r(_r)
, g(_g)
, b(_b)
, a(_a)
{}

bool Color4F::operator==(const Color4F& right) const
{
    return (r == right.r && g == right.g && b == right.b && a == right.a);
}

bool Color4F::operator!=(const Color4F& right) const
{
    return !(*this == right);
}

const Color4F Color4F::WHITE  (    1,     1,     1, 1);
const Color4F Color4F::YELLOW (    1,     1,     0, 1);
const Color4F Color4F::GREEN  (    0,     1,     0, 1);
const Color4F Color4F::BLUE   (    0,     0,     1, 1);
const Color4F Color4F::RED    (    1,     0,     0, 1);
const Color4F Color4F::MAGENTA(    1,     0,     1, 1);
const Color4F Color4F::BLACK  (    0,     0,     0, 1);
const Color4F Color4F::ORANGE (    1,  0.5f,     0, 1);
const Color4F Color4F::GRAY   (0.65f, 0.65f, 0.65f, 1);

NS_CC_END
