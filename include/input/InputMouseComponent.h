#pragma once

#include <input/MouseInput.h>
#include <input/InputComponent.h>

namespace Gengine
{
    class InputMouseComponent : public InputComponent
    {
    public:
        InputMouseComponent();
        ~InputMouseComponent();

        void HandleInput(const Input &input) override;
    protected:
        virtual void HandleMouseMoved(const Input &input) = 0;
        virtual void HandleMouseButtonPressed(const Input &input) = 0;
        virtual void HandleMouseButtonReleased(const Input &input) = 0;
    };
}