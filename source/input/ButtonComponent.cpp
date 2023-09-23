#include <core/Logger.h>
#include <input/ButtonComponent.h>
#include <typeinfo>

namespace Gengine
{
    ButtonComponent::ButtonComponent(const Vector2D &size)
        : mSize(size)
    {
    }
    ButtonComponent::~ButtonComponent() {}

    bool ButtonComponent::HandleMouseMoved(const Input &input)
    {
        const MouseMovedInput &mouseInput = dynamic_cast<const MouseMovedInput &>(input);
        L_TRACE("[BUTTON COMPONENT]", "Mouse Moved: %s", mouseInput.ToString().c_str());

        AnimateEvent event;
        if (IsActive(mouseInput.mMouseX, mouseInput.mMouseY))
        {
            L_TRACE("[BUTTON COMPONENT]", "Active");
            mEntity->mEventHandler.Trigger("hoverStart", event);

            return true;
        }
        else
        {
            L_TRACE("[BUTTON COMPONENT]", "Inactive");
            mEntity->mEventHandler.Trigger("hoverEnd", event);

            return false;
        }
    }
    bool ButtonComponent::HandleMouseButtonPressed(const Input &input)
    {
        const MouseButtonPressedInput &mouseInput = dynamic_cast<const MouseButtonPressedInput &>(input);
        L_INFO("[BUTTON COMPONENT]", "Mouse Pressed: %s", mouseInput.ToString().c_str());

        if (IsActive(mouseInput.mMouseX, mouseInput.mMouseY))
        {
            AnimateEvent event;
            L_INFO("[BUTTON COMPONENT]", "Active");
            mEntity->mEventHandler.Trigger("onClick", event);

            return true;
        }

        return false;
    }

    bool ButtonComponent::HandleMouseButtonReleased(const Input &input)
    {
        const MouseButtonReleasedInput &mouseInput = dynamic_cast<const MouseButtonReleasedInput &>(input);
        L_INFO("[BUTTON COMPONENT]", "Mouse Released: %s", mouseInput.ToString().c_str());

        return false;
    }

    bool ButtonComponent::IsActive(int32 x, int32 y)
    {
        const Vector2D position = mEntity->mPosition;
        mBounds = Box2D(position.mX, position.mY, mSize.mX, mSize.mY, true, true);

        return (x >= mBounds.mX &&
                x <= mBounds.mX + mBounds.mW &&
                y >= mBounds.mY &&
                y <= mBounds.mY + mBounds.mH);
    }
}