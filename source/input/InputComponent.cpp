#include <input/InputComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    InputComponent::InputComponent() {}

    InputComponent::~InputComponent() {}

    void InputComponent::Create() {}

    void InputComponent::Update() {}

    void InputComponent::Dispose() {}

    void InputComponent::HandleInput(const Input &input)
    {
        L_INFO("[INPUT COMPONENT]", "Receiving Input");
    }
}