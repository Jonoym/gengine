#include <input/InputComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputComponent::InputComponent(InputPriority priority)
        : mInputPriority(priority)
    {
        ServiceManager::GetServiceManager().GetInputHandler().Register(this);
    }

    InputComponent::~InputComponent() {}

    void InputComponent::Dispose()
    {
        ServiceManager::GetServiceManager().GetInputHandler().Deregister(this);
    }

    bool InputComponent::HandleInput(const Input &input)
    {
        L_TRACE("[INPUT COMPONENT]", "Receiving Input");
        return false;
    }

    void InputComponent::HandleInactive(const Input &input)
    {
    }
}