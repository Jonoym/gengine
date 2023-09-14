#pragma once

#include <Includes.h>

namespace Gengine
{
    class InputHandler
    {
    public:
        InputHandler();
        ~InputHandler();
        void HandleInput();
        bool ShouldQuit();

    private:
        bool mQuit;
    };
}