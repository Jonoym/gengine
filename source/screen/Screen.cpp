#include <screen/Screen.h>
#include <core/Logger.h>


namespace Gengine 
{
    Screen::Screen()
    {

    }

    Screen::~Screen()
    {

    }

    bool Screen::Initialise()
    {
        L_INFO("[SCREEN]", "Initialising Screen");

        if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
            L_FATAL("[SCREEN]", "Failed to initialise SDL: %s", SDL_GetError());
            return false;
        } 

        mWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        if (!mWindow) 
        {
            L_FATAL("[SCREEN]", "Failed to create wthe window SDL: %s", SDL_GetError());
            return false;
        }

        return true;
    }
    
    void Screen::Exit()
    {
        L_INFO("[SCREEN]", "Destroying and Exiting Screen");

	    SDL_DestroyWindow( mWindow );
        SDL_Quit();
    }

}