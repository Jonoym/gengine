#pragma once

#include <components/Component.h>
#include <input/Input.h>

namespace Gengine
{
    class InputComponent : public Component
    {
    public:
        InputComponent();
        ~InputComponent();

        virtual bool HandleInput(const Input &input);
        virtual void HandleInactive();
    };
}