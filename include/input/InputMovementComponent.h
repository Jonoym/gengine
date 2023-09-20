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

        void HandleInput(const Input &input) override;
    private:
        void HandleKeyPressed(const Input &input);
        void HandleKeyReleased(const Input &input);
    };
}