#pragma once

#include <components/Component.h>
#include <core/KeyCodes.h>
#include <input/Input.h>
#include <input/KeyInput.h>
#include <input/InputComponent.h>

namespace Gengine
{
    class InputMovementComponent : public InputComponent
    {
    public:
        InputMovementComponent();
        ~InputMovementComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;
        void HandleInput(const Input &input) override;
    };
}