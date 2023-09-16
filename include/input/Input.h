#pragma once

#include <Includes.h>

namespace Gengine
{
    enum class InputType
    {
        NONE = 0,
        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WINDOW_FOCUS,
        WINDOW_LOST_FOCUS,
        WINDOW_MOVED,
        APP_TICK,
        APP_UDPATE,
        APP_RENDER,
        KEY_PRESSED,
        KEY_RELEASED,
        KEY_TYPED,
        MOUSE_BUTTON_PRESSED,
        MOUSE_BUTTON_RELEASED,
        MOUSE_MOVED,
        MOUSE_SCROLLED
    };

    enum InputCategory
    {
        NONE = 0,
        INPUT_CATEGORY_APPLICATION = BIT(1),
        INPUT_CATEGORY_INPUT = BIT(2),
        INPUT_CATEGORY_KEYBOARD = BIT(3),
        INPUT_CATEGORY_MOUSE = BIT(4),
        INPUT_CATEGORY_MOUSE_BUTTON = BIT(5)
    };

#define EVENT_CLASS_TYPE(type) static InputType GetStaticType() { return InputType::type; }\
								virtual InputType GetInputType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Input
    {
    public:
        virtual ~Input() = default;

        virtual InputType GetInputType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const
        {
            return GetName();
        }

        bool IsInCategory(InputCategory category)
        {
            return GetCategoryFlags() & category;
        }

        bool mHandled = false;
    };
}