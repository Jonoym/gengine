#pragma once

#include <Types.h>

namespace Gengine
{
    class Vector2D {

    public:
        Vector2D();
        Vector2D(float xCoord, float yCoord);
        Vector2D(const Vector2D& vector);
        Vector2D& operator= (const Vector2D& other);

        bool operator== (const Vector2D& other);
        Vector2D operator+ (const Vector2D& other);
        Vector2D operator- (const Vector2D& other);
    
    private:
        float32 x;
        float32 y;

    };
}