#pragma once

#include <Includes.h>
#include <Types.h>
#include <cmath>
#include <algorithm>

namespace Gengine
{
    struct Coord
    {
        int32 mX;
        int32 mY;
    };

    class Vector2D {

    public:
        static const Vector2D ZERO;
        static const Vector2D LEFT;
        static const Vector2D RIGHT;
        static const Vector2D UP;
        static const Vector2D DOWN;

        Vector2D();
        Vector2D(int32 xCoord, int32 yCoord);
        Vector2D(float32 xCoord, float32 yCoord);
        Vector2D(const Vector2D& vector);
        Vector2D& operator+= (const Vector2D& other);
        Vector2D& operator-= (const Vector2D& other);
        Vector2D& operator= (const Vector2D& other);

        bool operator== (const Vector2D& other) const;
        Vector2D operator+ (const Vector2D& other) const;
        Vector2D operator* (const Vector2D& other) const;
        Vector2D operator* (float32 scalar) const;
        Vector2D operator/ (float32 scalar) const;
        Vector2D operator- (const Vector2D& other) const;

        const float32 Length() const;
        const Vector2D Normalise() const;
    
        float32 mX;
        float32 mY;
    };
}