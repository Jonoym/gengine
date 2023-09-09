#include "Game.h"

Game::Game(int32 screenWidth, int32 screenHeight, bool fullscreen)
    : mScreenWidth(screenWidth)
    , mScreenHeight(screenHeight)
    , mIsFullscreen(fullscreen)
{
}

Game::~Game()
{
}

void Game::start()
{
    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        startGameLoop();
    }

    close();
}

bool Game::init()
{

    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        mWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
        if (mWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
            if (mRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

void Game::close()
{
    // Destroy window
    SDL_DestroyWindow(mWindow);

    // Quit SDL subsystems
    SDL_Quit();
}

void Game::startGameLoop()
{
    ServiceManager& serviceManager = ServiceManager::getServiceManager();

    serviceManager.registerRendererService(new RendererService(mRenderer));
    serviceManager.registerTimeService(new TimeService());
    bool quit = false;
    while (!quit)
    {
        // Get window surface
        mScreenSurface = SDL_GetWindowSurface(mWindow);

        // Fill the surface white
        SDL_FillRect(mScreenSurface, NULL, SDL_MapRGB(mScreenSurface->format, 0xFF, 0xFF, 0xFF));

        // Update the surface
        SDL_UpdateWindowSurface(mWindow);

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

    serviceManager.dispose();

}
