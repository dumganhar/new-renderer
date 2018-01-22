/****************************************************************************
 Copyright (c) 2018 Chukong Technologies

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#pragma once

#include "base/macros.h"

#include <string>

NS_CC_BEGIN

class CC_DLL Size
{
public:
    /**Width of the Size.*/
    float width;
    /**Height of the Size.*/
    float height;
public:
    /**Conversion from Vec2 to Size.*/
    operator Vec2() const
    {
        return Vec2(width, height);
    }

public:
    /**
     @{
     Constructor.
     @param width Width of the size.
     @param height Height of the size.
     @param other Copy constructor.
     @param point Conversion from a point.
     */
    Size();
    Size(float width, float height);
    Size(const Size& other);
    explicit Size(const Vec2& point);
    /**@}*/

    /**
     * @js NA
     * @lua NA
     */
    Size& operator= (const Size& other);
    /**
     * @js NA
     * @lua NA
     */
    Size& operator= (const Vec2& point);
    /**
     * @js NA
     * @lua NA
     */
    Size operator+(const Size& right) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator-(const Size& right) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator*(float a) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator/(float a) const;
    /**
     Set the width and height of Size.
     * @js NA
     * @lua NA
     */
    void setSize(float width, float height);
    /**
     Check if two size is the same.
     * @js NA
     */
    bool equals(const Size& target) const;
    /**Size(0,0).*/
    static const Size ZERO;
};

/**
 * RGB color composed of bytes 3 bytes.
 * @since v3.0
 */
struct CC_DLL Color3B
{
    Color3B();
    Color3B(uint8_t _r, uint8_t _g, uint8_t _b);

    bool operator==(const Color3B& right) const;
    bool operator!=(const Color3B& right) const;

    bool equals(const Color3B& other) const
    {
        return (*this == other);
    }

    uint8_t r;
    uint8_t g;
    uint8_t b;

    static const Color3B WHITE;
    static const Color3B YELLOW;
    static const Color3B BLUE;
    static const Color3B GREEN;
    static const Color3B RED;
    static const Color3B MAGENTA;
    static const Color3B BLACK;
    static const Color3B ORANGE;
    static const Color3B GRAY;
};

/** @struct FontShadow
 * Shadow attributes.
 */
struct CC_DLL FontShadow
{
public:

    // shadow is not enabled by default
    FontShadow()
    : _shadowEnabled(false)
    , _shadowBlur(0)
    , _shadowOpacity(0)
    {}

    /// true if shadow enabled
    bool   _shadowEnabled;
    /// shadow x and y offset
    Size   _shadowOffset;
    /// shadow blurrines
    float  _shadowBlur;
    /// shadow opacity
    float  _shadowOpacity;
};

/** @struct FontStroke
 * Stroke attributes.
 */
struct CC_DLL FontStroke
{
public:

    // stroke is disabled by default
    FontStroke()
    : _strokeSize(0.0f)
    , _strokeColor(Color3B::BLACK)
    , _strokeAlpha(255)
    , _strokeEnabled(false)
    {}

    /// stroke size
    float     _strokeSize;
    /// stroke color
    Color3B   _strokeColor;
    /// stroke alpha
    uint8_t   _strokeAlpha;
    /// true if stroke enabled
    bool      _strokeEnabled;
};

/** @struct TextVAlignment
 * Vertical text alignment type.
 *
 * @note If any of these enums are edited and/or reordered, update Texture2D.m.
 */
enum class CC_DLL TextVAlignment : char
{
    TOP,
    CENTER,
    BOTTOM
};

/** @struct TextHAlignment
 * Horizontal text alignment type.
 *
 * @note If any of these enums are edited and/or reordered, update Texture2D.m.
 */
enum class CC_DLL TextHAlignment : char
{
    LEFT,
    CENTER,
    RIGHT
};

/** @struct FontDefinition
 * Font attributes.
 */
struct CC_DLL FontDefinition
{
public:
    /**
     * @js NA
     * @lua NA
     */
    FontDefinition()
    : _fontSize(0)
    , _alignment(TextHAlignment::CENTER)
    , _vertAlignment(TextVAlignment::TOP)
    , _dimensions(Size::ZERO)
    , _fontFillColor(Color3B::WHITE)
    , _fontAlpha(255)
    , _enableWrap(true)
    , _overflow(0)
    {}

    /// font name
    std::string           _fontName;
    /// font size
    int                   _fontSize;
    /// enable shrink font size
    int                  _overflow;
    /// rendering box
    Size                  _dimensions;
    /// font color
    Color3B               _fontFillColor;
    /// font alpha
    uint8_t               _fontAlpha;
    /// font shadow
    FontShadow            _shadow;
    /// font stroke
    FontStroke            _stroke;
    /// horizontal alignment
    TextHAlignment        _alignment;
    /// vertical alignment
    TextVAlignment _vertAlignment;
    /// enable text wrap
    bool                  _enableWrap;
    bool                 _enableBold;
};

/** Defines the alignment of text. */
enum class TextAlign
{
    CENTER        = 0x33, /** Horizontal center and vertical center. */
    TOP           = 0x13, /** Horizontal center and vertical top. */
    TOP_RIGHT     = 0x12, /** Horizontal right and vertical top. */
    RIGHT         = 0x32, /** Horizontal right and vertical center. */
    BOTTOM_RIGHT  = 0x22, /** Horizontal right and vertical bottom. */
    BOTTOM        = 0x23, /** Horizontal center and vertical bottom. */
    BOTTOM_LEFT   = 0x21, /** Horizontal left and vertical bottom. */
    LEFT          = 0x31, /** Horizontal left and vertical center. */
    TOP_LEFT      = 0x11, /** Horizontal left and vertical top. */
};

NS_CC_END
