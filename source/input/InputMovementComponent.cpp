#include <input/InputMovementComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputMovementComponent::InputMovementComponent() {}

    InputMovementComponent::~InputMovementComponent() {}

    void InputMovementComponent::Create() {}

    void InputMovementComponent::Update() {}

    void InputMovementComponent::Dispose() {}

    void InputMovementComponent::HandleInput(const Input &input)
    {
        L_INFO("[MOVEMENT INPUT COMPONENT]", "Receiving Input");
        switch (input.GetInputType())
        {
        case InputType::KEY_PRESSED:
        {
            HandleKeyPressed(input);
            break;
        }
        case InputType::KEY_RELEASED:
        {
            HandleKeyReleased(input);
            break;
        }
        }
    }

    void InputMovementComponent::HandleKeyPressed(const Input &input)
    {
        const KeyInput &keyInput = dynamic_cast<const KeyInput &>(input);
        L_INFO("[MOVEMENT INPUT COMPONENT]", "Key Pressed: %s", keyInput.ToString().c_str());

        switch (keyInput.GetKeyCode())
        {
        case Key::Left:
            mEntity->mEventHandler.Trigger("moveLeftStart");
            break;
        case Key::Right:
            mEntity->mEventHandler.Trigger("moveRightStart");
            break;
        case Key::Up:
            mEntity->mEventHandler.Trigger("moveUpStart");
            break;
        case Key::Down:
            mEntity->mEventHandler.Trigger("moveDownStart");
            break;
        }
    }

    void InputMovementComponent::HandleKeyReleased(const Input &input)
    {
        const KeyInput &keyInput = dynamic_cast<const KeyInput &>(input);
        L_INFO("[MOVEMENT INPUT COMPONENT]", "Key Released: %s", keyInput.ToString().c_str());

        switch (keyInput.GetKeyCode())
        {
        case Key::Left:
            mEntity->mEventHandler.Trigger("moveLeftEnd");
            break;
        case Key::Right:
            mEntity->mEventHandler.Trigger("moveRightEnd");
            break;
        case Key::Up:
            mEntity->mEventHandler.Trigger("moveUpEnd");
            break;
        case Key::Down:
            mEntity->mEventHandler.Trigger("moveDownEnd");
            break;
        }
    }
}