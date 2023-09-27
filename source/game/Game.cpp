#include <game/Game.h>
#include <screens/Screen.h>
#include <core/Logger.h>

namespace Gengine
{
    Game::Game() {}

    Game::~Game() {}

    void Game::Initialise()
    {
        L_INFO("[GAME]", "Initialising Game");

        SetScreen(std::make_unique<Screen>());
    }

    void Game::SetScreen(std::unique_ptr<IScreen> screen)
    {
        L_INFO("[GAME]", "Setting the Current Screen");
        mScreen = std::move(screen);
    }

    void Game::MainLoop()
    {
        L_INFO("[GAME]", "Starting Game Main Loop");

        mScreen->Initialise();

        bool running = true;
        while (running)
        {
            bool shouldQuit = mScreen->Update();

            if (shouldQuit)
            {
                L_INFO("[GAME]", "Main Game Loop is Exiting");
                running = false;
            }
        }
    }

    void Game::Dispose()
    {
        L_INFO("[GAME]", "Disposing Game");
    }

    void Game::ChangeScreen(const std::string &screenId)
    {
    }

    void Game::AddScreen(const std::string &screenId, const IScreen &screen)
    {
    }
}