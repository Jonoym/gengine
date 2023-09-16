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
        if (input.GetInputType() == InputType::KEY_PRESSED)
        {
            const KeyInput& keyInput = dynamic_cast<const KeyInput&>(input);
            L_INFO("[MOVEMENT INPUT COMPONENT]", "Key Pressed: %s", keyInput.ToString().c_str());

            switch(keyInput.GetKeyCode())
            {
                case Key::Left:
                    mEntity->mEventHandler.Trigger("moveLeft");
                    break;
                case Key::Right:
                    mEntity->mEventHandler.Trigger("moveRight");
                    break;
                case Key::Up:
                    mEntity->mEventHandler.Trigger("moveUp");
                    break;
                case Key::Down:
                    mEntity->mEventHandler.Trigger("moveDown");
                    break;
            }

        }
    }
}