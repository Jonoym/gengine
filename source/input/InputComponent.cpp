#include <input/InputComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputComponent::InputComponent() {
        ServiceManager::GetServiceManager().GetInputHandler().Register(this);
    }

    InputComponent::~InputComponent() {}

    bool InputComponent::HandleInput(const Input &input)
    {
        L_TRACE("[INPUT COMPONENT]", "Receiving Input");
        return false;
    }

    void InputComponent::HandleInactive()
    {
    }
}