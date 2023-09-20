#pragma once

#include <input/Input.h>

namespace Gengine
{
    class MouseMovedInput : public Input
    {
    public:
        MouseMovedInput(const int32 x, const int32 y)
            : mMouseX(x), mMouseY(y) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedInput: { " << mMouseX << ", " << mMouseY << " }";
            return ss.str();
        }

        INPUT_CLASS_TYPE(MOUSE_MOVED)
		INPUT_CLASS_CATEGORY(INPUT_CATEGORY_MOUSE | INPUT_CATEGORY_INPUT)

        int32 mMouseX;
        int32 mMouseY;
    };

    class MouseScrolledInput : public Input
    {

    };

	class MouseButtonInput : public Input
	{
	public:
		MouseCode GetMouseButton() const { return mButton; }

		INPUT_CLASS_CATEGORY(INPUT_CATEGORY_MOUSE | INPUT_CATEGORY_INPUT | INPUT_CATEGORY_MOUSE_BUTTON)

		MouseCode mButton;
        int32 mMouseX;
        int32 mMouseY;
	protected:
		MouseButtonInput(const MouseCode button, const int32 x, const int32 y)
			: mButton(button)
            , mMouseX(x)
            , mMouseY(y)
            {}
	};

	class MouseButtonPressedInput : public MouseButtonInput
	{
	public:
		MouseButtonPressedInput(const MouseCode button, const int32 x, const int32 y)
			: MouseButtonInput(button, x, y) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedInput: " << mButton << " { " << mMouseX << ", " << mMouseY << " }";
			return ss.str();
		}

		INPUT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	};

	class MouseButtonReleasedInput : public MouseButtonInput
	{
	public:
		MouseButtonReleasedInput(const MouseCode button, const int32 x, const int32 y)
			: MouseButtonInput(button, x, y) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedInput: " << mButton << " { " << mMouseX << ", " << mMouseY << " }";
			return ss.str();
		}

		INPUT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
	};
}