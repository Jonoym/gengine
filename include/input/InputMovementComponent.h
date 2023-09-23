#pragma once

#include <input/KeyInput.h>
#include <input/InputComponent.h>

namespace Gengine
{
    class InputMovementComponent : public InputComponent
    {
    public:
        InputMovementComponent();
        ~InputMovementComponent();

        bool HandleInput(const Input &input) override;
    private:
        bool HandleKeyPressed(const Input &input);
        bool HandleKeyReleased(const Input &input);
    };
}