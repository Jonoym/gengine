#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Types.h"
#include "services/ServiceManager.h"
#include "timing/TimeService.h"
#include "graphics/RendererService.h"

class Game
{

public:
    Game(int32 screenWidth, int32 screenHeight, bool fullscreen);
    ~Game();

    void start();
    bool init();
    void close();
    void startGameLoop();
    // void gameLoop();

private:
    int32 mScreenWidth;
    int32 mScreenHeight;
    bool mIsFullscreen;
    
    // The window we'll be rendering to
    SDL_Window *mWindow = NULL;

    // The surface contained by the window
    SDL_Surface *mScreenSurface = NULL;

    //The window renderer
    SDL_Renderer* mRenderer = NULL;

};