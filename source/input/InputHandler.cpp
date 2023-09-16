#include <SDL2/SDL.h>

#include <input/InputHandler.h>
#include <input/KeyInput.h>
#include <input/MouseInput.h>
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
            L_TRACE("[INPUT HANDLER]", "Handling Input Event");
            if (e.type == SDL_QUIT) mQuit = true;
            switch(e.type)
            {
                case SDL_KEYDOWN:
                    DispatchInputEvent(KeyPressedInput{e.key.keysym.sym, true});
                    break;
                case SDL_KEYUP:
                    DispatchInputEvent(KeyReleasedInput{e.key.keysym.sym});
                    break;
            }
        }
    }

    void InputHandler::DispatchInputEvent(const Input& input)
    {
        L_INFO("[INPUT HANDLER]", "Dispatching Input Events");
        for (auto& inputListener : mInputComponents)
        {
            L_INFO("[INPUT HANDLER]", "Dispatched");
            inputListener->HandleInput(input);
        }

    }

    bool InputHandler::ShouldQuit()
    {
        return mQuit;
    }

    void InputHandler::Register(const std::shared_ptr<Component> component) {
        L_INFO("[INPUT HANDLER]", "Registering Input Component");
        mInputComponents.push_back(std::dynamic_pointer_cast<InputComponent>(component));
    }

}