#pragma once

#include <input/Input.h>

namespace Gengine
{
    class MouseMovedInput : public Input
    {
    public:
        MouseMovedInput(const float32 x, const float32 y)
            : mMouseX(x), mMouseY(y) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedInput: {" << mMouseX << ", " << mMouseY << "}";
            return ss.str();
        }

    private:
        float32 mMouseX;
        float32 mMouseY;
    };

    class MouseScrolledInput : public Input
    {

    };

    class MouseButtonInput : public Input
    {

    };
}