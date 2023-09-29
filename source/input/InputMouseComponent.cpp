#include <input/InputMouseComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>
#include <events/EventTypes.h>

namespace Gengine
{
    InputMouseComponent::InputMouseComponent()
        : InputComponent(InputPriority::ENTITY)
    {}

    InputMouseComponent::~InputMouseComponent() {}

    bool InputMouseComponent::HandleInput(const Input &input)
    {
        L_TRACE("[MOUSE INPUT COMPONENT]", "Receiving Input of Type: { %d }", input.GetInputType());
        switch (input.GetInputType())
        {
        case InputType::MOUSE_MOVED:
        {
            L_TRACE("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Moved");
            return HandleMouseMoved(input);
        }
        case InputType::MOUSE_BUTTON_PRESSED:
        {
            L_TRACE("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Pressed");
            return HandleMouseButtonPressed(input);
        }
        case InputType::MOUSE_BUTTON_RELEASED:
        {
            L_TRACE("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Released");
            return HandleMouseButtonReleased(input);
        }
        }
        return false;
    }

    bool InputMouseComponent::HandleMouseMoved(const Input &input)
    {
      const MouseMovedInput &mouseInput = dynamic_cast<const MouseMovedInput &>(input);
        L_TRACE("[MOUSE INPUT COPMONENT]", "Mouse Moved: %s", mouseInput.ToString().c_str());

        MouseEvent event(mouseInput.mMouseX, mouseInput.mMouseY);
        mEntity->mEventHandler.Trigger("onMove", event);

        return false;
    }

    bool InputMouseComponent::HandleMouseButtonPressed(const Input &input)
    {
        const MouseButtonPressedInput &mouseInput = dynamic_cast<const MouseButtonPressedInput &>(input);
        L_INFO("[MOUSE INPUT COPMONENT]", "Mouse Pressed: %s", mouseInput.ToString().c_str());

        MouseEvent event(mouseInput.mMouseX, mouseInput.mMouseY);
        mEntity->mEventHandler.Trigger("onClick", event);

        return false;
    }

    bool InputMouseComponent::HandleMouseButtonReleased(const Input &input)
    {
        const MouseButtonReleasedInput &mouseInput = dynamic_cast<const MouseButtonReleasedInput &>(input);
        L_INFO("[MOUSE INPUT COPMONENT]", "Mouse Released: %s", mouseInput.ToString().c_str());

        MouseEvent event(mouseInput.mMouseX, mouseInput.mMouseY);
        mEntity->mEventHandler.Trigger("onRelease", event);

        return false;
    }
}