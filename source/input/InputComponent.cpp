#include <input/InputComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputComponent::InputComponent() {
        ServiceManager::GetServiceManager().GetInputHandler().Register(this);
    }

    InputComponent::~InputComponent() {}

    void InputComponent::HandleInput(const Input &input)
    {
        L_INFO("[INPUT COMPONENT]", "Receiving Input");
    }
}