#include <core/Logger.h>
#include <events/EventTypes.h>
#include <input/InputMovementComponent.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    InputMovementComponent::InputMovementComponent()
        : InputComponent(InputPriority::ENTITY)
    {
    }

    InputMovementComponent::~InputMovementComponent() {}

    bool InputMovementComponent::HandleInput(const Input &input)
    {
        L_TRACE("[MOVEMENT INPUT COMPONENT]", "Receiving Input of Type: { %d }", input.GetInputType());
        switch (input.GetInputType())
        {
        case InputType::KEY_PRESSED:
        {
            return HandleKeyPressed(input);
        }
        case InputType::KEY_RELEASED:
        {
            return HandleKeyReleased(input);
        }
        }

        return false;
    }

    bool InputMovementComponent::HandleKeyPressed(const Input &input)
    {
        const KeyInput &keyInput = dynamic_cast<const KeyInput &>(input);
        L_TRACE("[MOVEMENT INPUT COMPONENT]", "Key Pressed: %s", keyInput.ToString().c_str());

        MovementEvent event;

        switch (keyInput.GetKeyCode())
        {
        case Key::A:
            mEntity->mEventHandler.Trigger("moveLeftStart", event);
            return true;
        case Key::D:
            mEntity->mEventHandler.Trigger("moveRightStart", event);
            return true;
        case Key::W:
            mEntity->mEventHandler.Trigger("moveUpStart", event);
            return true;
        case Key::S:
            mEntity->mEventHandler.Trigger("moveDownStart", event);
            return true;
        }
        return false;
    }

    bool InputMovementComponent::HandleKeyReleased(const Input &input)
    {

        const KeyInput &keyInput = dynamic_cast<const KeyInput &>(input);
        L_TRACE("[MOVEMENT INPUT COMPONENT]", "Key Released: %s", keyInput.ToString().c_str());
        
        MovementEvent event;

        switch (keyInput.GetKeyCode())
        {
        case Key::A:
            mEntity->mEventHandler.Trigger("moveLeftEnd", event);
            return true;
        case Key::D:
            mEntity->mEventHandler.Trigger("moveRightEnd", event);
            return true;
        case Key::W:
            mEntity->mEventHandler.Trigger("moveUpEnd", event);
            return true;
        case Key::S:
            mEntity->mEventHandler.Trigger("moveDownEnd", event);
            return true;
        }
        return false;
    }
}