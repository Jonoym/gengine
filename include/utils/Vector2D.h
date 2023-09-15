#pragma once

#include <Includes.h>
#include <Types.h>

namespace Gengine
{
    class Vector2D {

    public:
        Vector2D();
        Vector2D(int32 xCoord, int32 yCoord);
        Vector2D(float32 xCoord, float32 yCoord);
        Vector2D(const Vector2D& vector);
        Vector2D& operator= (const Vector2D& other);

        bool operator== (const Vector2D& other);
        Vector2D operator+ (const Vector2D& other);
        Vector2D operator- (const Vector2D& other);
    
        float32 x;
        float32 y;
    };
}