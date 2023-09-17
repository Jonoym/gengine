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

        void Create() override;
        void Update() override;
        void Dispose() override;
        virtual void HandleInput(const Input &input);
    };
}