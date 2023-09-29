#pragma once

#include <components/Component.h>
#include <input/Input.h>

namespace Gengine
{
    enum class InputPriority
    {
        BACKGROUND = 0,
        ENTITY = 1,
        OVERLAY = 2
    };

    class InputComponent : public Component
    {
    public:
        InputComponent(InputPriority priority);
        ~InputComponent();

        void Dispose() override;

        virtual bool HandleInput(const Input &input);
        virtual void HandleInactive(const Input &input);

        InputPriority mInputPriority;
    };
}