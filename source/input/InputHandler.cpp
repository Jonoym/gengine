#include <SDL2/SDL.h>

#include <input/InputHandler.h>
#include <input/KeyInput.h>
#include <input/MouseInput.h>
#include <core/Logger.h>
#include <entities/Entity.h>

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

            switch (e.type)
            {
            case SDL_KEYDOWN:
                DispatchInputEvent(KeyPressedInput{e.key.keysym.sym, false});
                break;
            case SDL_KEYUP:
                DispatchInputEvent(KeyReleasedInput{e.key.keysym.sym});
                break;
            case SDL_MOUSEMOTION:
                L_TRACE("[INPUT HANDLER]", "Setting Value to x: %d, y: %d", e.motion.x, e.motion.y);
                DispatchInputEvent(MouseMovedInput{e.motion.x, e.motion.y});
                break;
            case SDL_MOUSEBUTTONDOWN:
                L_TRACE("[INPUT HANDLER]", "Mouse Button Down at Location x: %d, y: %d", e.motion.x, e.motion.y);
                DispatchInputEvent(MouseButtonPressedInput{ConvertMouseButton(e.button.button), e.motion.x, e.motion.y});
                break;
            case SDL_MOUSEBUTTONUP:
                L_TRACE("[INPUT HANDLER]", "Mouse Button Up at Location x: %d, y: %d", e.motion.x, e.motion.y);
                DispatchInputEvent(MouseButtonReleasedInput{ConvertMouseButton(e.button.button), e.motion.x, e.motion.y});
                break;
            }
        }
    }

    void InputHandler::DispatchInputEvent(const Input &input)
    {
        L_TRACE("[INPUT HANDLER]", "Dispatching Input Events");
        OrderInputComponents();
        for (auto &inputListener : mInputComponents)
        {
            bool handled = inputListener->HandleInput(input);

            if (handled) break;
        }
    }


    void InputHandler::OrderInputComponents()
    {
        std::sort(mInputComponents.begin(), mInputComponents.end(),
                  [](InputComponent *a, InputComponent *b)
                  {
                      return (b->mEntity->mPosition.mY) < (a->mEntity->mPosition.mY );
                  });
    }

    bool InputHandler::ShouldQuit()
    {
        return mQuit;
    }

    MouseCode InputHandler::ConvertMouseButton(uint8 buttonInput)
    {
        switch (buttonInput)
        {
        case SDL_BUTTON_LEFT:
            return Mouse::Left;
        case SDL_BUTTON_RIGHT:
            return Mouse::Right;
        case SDL_BUTTON_MIDDLE:
            return Mouse::Middle;
        default:
            return Mouse::None;
        }
    }

    void InputHandler::Register(InputComponent *component)
    {
        L_INFO("[INPUT HANDLER]", "Registering Input Component");
        mInputComponents.push_back(component);
    }

}