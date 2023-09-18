
#pragma once

#include <Includes.h>
#include <input/InputComponent.h>

namespace Gengine
{
    struct IInputHandler
    {
        virtual bool ShouldQuit() = 0;
        virtual void HandleInput() = 0;
        virtual void DispatchInputEvent(const Input& input) = 0;
        virtual void Register(InputComponent* component) = 0;

        std::vector<InputComponent*> mInputComponents;
    };
}