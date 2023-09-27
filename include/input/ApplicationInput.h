#pragma once

#include <input/Input.h>

namespace Gengine
{
    class WindowResizeInput : public Input
    {
    public:
        WindowResizeInput(uint32 width, uint32 height) : mWidth(width), mHeight(height) {}

        uint32 GetWidth() const { return mWidth; }
        uint32 GetHeight() const { return mHeight; }

        INPUT_CLASS_CATEGORY(INPUT_CATEGORY_APPLICATION | INPUT_CATEGORY_INPUT)

        INPUT_CLASS_TYPE(WINDOW_RESIZE)

        uint32 mWidth;
        uint32 mHeight;
    };

}