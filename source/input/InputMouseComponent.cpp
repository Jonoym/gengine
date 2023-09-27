#include <input/InputMouseComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

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
            L_INFO("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Pressed");
            return HandleMouseButtonPressed(input);
        }
        case InputType::MOUSE_BUTTON_RELEASED:
        {
            L_INFO("[MOUSE INPUT COMPONENT]", "Handling Mouse Button Released");
            return HandleMouseButtonReleased(input);
        }
        }
        return false;
    }
}