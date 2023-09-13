#include <game/Game.h>
#include <scenes/Scene.h>
#include <core/Logger.h>

namespace Gengine
{
    Game::Game() {}

    Game::~Game() {}

    void Game::Initialise()
    {
        L_INFO("[GAME]", "Initialising Game");

        SetScene(std::make_unique<Scene>());
    }

    void Game::SetScene(std::unique_ptr<IScene> scene)
    {
        L_INFO("[GAME]", "Setting the current scene");
        mScene = std::move(scene);
    }

    void Game::MainLoop()
    {
        L_INFO("[GAME]", "Starting Game Main Loop");
        bool running = true;
        while (running)
        {
            mScene->Update();

            running = false;
        }
    }

    void Game::Dispose()
    {
        L_INFO("[GAME]", "Disposing Game");

    }

    // void Game::ChangeScene(const std::string &sceneId)
    // {
    // }

    // void Game::AddScene(const std::string &sceneId, const IScene &scene)
    // {
    // }
}