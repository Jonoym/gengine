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
            
            if (e.type == SDL_KEYDOWN) {
                L_INFO("[INPUT HANDLER]", "Dispatching Input Event");
            }
        }
    }

    void InputHandler::DispatchInputEvent(const Input& input)
    {
        L_INFO("[INPUT HANDLER]", "Dispatching Input Event");

    }

    bool InputHandler::ShouldQuit()
    {
        return mQuit;
    }

    void InputHandler::Register(const std::shared_ptr<Component> component) {
        L_INFO("[INPUT HANDLER]", "Registering Input Component");
        mInputComponents.push_back(std::static_pointer_cast<InputComponent>(component));
    }

}