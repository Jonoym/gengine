#pragma once

#include <Includes.h>
#include <Types.h>

namespace Gengine
{
    class Box2D
    {

    public:
        Box2D();
        Box2D(const float32 x, const float32 y, const float32 w, const float32 h, bool xCentered, bool yCentered);
        Box2D(const int32 x, const int32 y, const int32 w, const int32 h, bool xCentered, bool yCentered);
        int32 mX;
        int32 mY;
        int32 mW;
        int32 mH;
    };
}