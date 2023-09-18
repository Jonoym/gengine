#include <utils/Box2D.h>

namespace Gengine
{
    Box2D::Box2D()
        : mX(0), mY(0), mW(0), mH(0)
    {}

    Box2D::Box2D(const float32 x, const float32 y, const float32 w, const float32 h, bool xCentered, bool yCentered) 
    : mX(xCentered ? static_cast<int>(x - w / 2) : x)
    , mY(yCentered ? static_cast<int>(y - h / 2) : y)
    , mW(static_cast<int>(w))
    , mH(static_cast<int>(h)) {}

    Box2D::Box2D(const int32 x, const int32 y, const int32 w, const int32 h, bool xCentered, bool yCentered) 
    : mX(xCentered ? static_cast<int>(x - w / 2) : x)
    , mY(yCentered ? static_cast<int>(y - h / 2) : y)
    , mW(w)
    , mH(h) {}
}