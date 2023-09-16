#pragma once

#include <Includes.h>
#include <Types.h>

namespace Gengine
{
    class Box2D
    {

    public:
        Box2D(float32 x, float32 y, float32 w, float32 h);
        float32 mX;
        float32 mY;
        float32 mW;
        float32 mH;
    };
}