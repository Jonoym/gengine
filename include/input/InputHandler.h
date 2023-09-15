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
        void DispatchInputEvent(const Input& input);
        bool ShouldQuit();

        void Register(const std::shared_ptr<Component> component) override;

    private:
        bool mQuit;
    };
}