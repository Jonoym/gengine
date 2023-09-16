#include <utils/Box2D.h>

namespace Gengine
{
    Box2D::Box2D(float32 x, float32 y, float32 w, float32 h) 
    : mX(x - w / 2), mY(y - h / 2), mW(w), mH(h) {}
}