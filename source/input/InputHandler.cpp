#include <SDL2/SDL.h>

#include <input/InputHandler.h>
#include <core/Logger.h>

namespace Gengine
{
    InputHandler::InputHandler()
        : mQuit(false)
    {
    }

    InputHandler::~InputHandler() {}

    void InputHandler::HandleInput()
    {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) mQuit = true;
        }
    }

    void InputHandler::DispatchInputEvent(const Input& input)
    {
        
    }

    bool InputHandler::ShouldQuit()
    {
        return mQuit;
    }

    void InputHandler::Register(const std::shared_ptr<Component> component) {

    }

}