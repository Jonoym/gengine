#include <input/InputMouseComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputMouseComponent::InputMouseComponent() {}

    InputMouseComponent::~InputMouseComponent() {}

    void InputMouseComponent::HandleInput(const Input &input)
    {
        L_INFO("[MOUSE INPUT COMPONENT]", "Receiving Input of Type: { %d }", input.GetInputType());
        switch (input.GetInputType())
        {
        case InputType::MOUSE_MOVED:
        {
            L_TRACE("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Moved");
            HandleMouseMoved(input);
            break;
        }
        case InputType::MOUSE_BUTTON_PRESSED:
        {
            L_INFO("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Pressed");
            HandleMouseButtonPressed(input);
            break;
        }
        case InputType::MOUSE_BUTTON_RELEASED:
        {
            L_TRACE("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Released");
            HandleMouseButtonReleased(input);
            break;
        }
        }
    }
}