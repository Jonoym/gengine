#include <gui/Interface.h>
#include <core/Logger.h>

namespace Gengine
{
    Interface::Interface()
    {
    }

    Interface::~Interface()
    {
    }

    bool Interface::Initialise()
    {
        L_INFO("[INTERFACE]", "Initialising Interface");

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            L_FATAL("[INTERFACE]", "Failed to initialise SDL: %s", SDL_GetError());
            return false;
        }

        // mWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        mWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
        if (!mWindow)
        {
            L_FATAL("[INTERFACE]", "Failed to create wthe window SDL: %s", SDL_GetError());
            return false;
        }

        if (IMG_Init(IMG_INIT_JPG) < 0)
        {
            L_FATAL("[INTERFACE]", "Failed to Initialise SDL_Image SDL: %s", IMG_GetError());
            return false;
        }

        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
        if (!mRenderer)
        {
            L_FATAL("[INTERFACE]", "Failed to Initialise Renderer SDL: %s", SDL_GetError());
            return false;
        }

        return true;
    }

    void Interface::Exit()
    {
        L_INFO("[SCREEN]", "Destroying and Exiting Screen");

        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        
        IMG_Quit();
        SDL_Quit();
    }

    SDL_Window *Interface::GetWindow()
    {
        return mWindow;
    }

    SDL_Renderer *Interface::GetRenderer()
    {
        return mRenderer;
    }

}