#pragma once

#include <Includes.h>
#include <input/Input.h>
#include <input/IInputHandler.h>

namespace Gengine
{
    class InputHandler : public IInputHandler
    {
    public:
        InputHandler();
        ~InputHandler();
        void HandleInput();
        void DispatchInputEvent(const Input& e);
        bool ShouldQuit();

        void Register(InputComponent* component) override;

    private:
        bool mQuit;
    };
}