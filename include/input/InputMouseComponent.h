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

        bool HandleInput(const Input &input) override;
    protected:
        virtual bool HandleMouseMoved(const Input &input) = 0;
        virtual bool HandleMouseButtonPressed(const Input &input) = 0;
        virtual bool HandleMouseButtonReleased(const Input &input) = 0;
    };
}