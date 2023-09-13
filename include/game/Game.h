#pragma once

#include <Includes.h>
#include <game/IGame.h>

namespace Gengine
{

    class Game : public IGame
    {

    public:

        Game();
        ~Game();

        void Initialise() override;
        void MainLoop() override;
        void SetScene(std::unique_ptr<IScene> scene) override;

        void Dispose() override;

        // void ChangeScene(const std::string &sceneId) override;
        // void AddScene(const std::string &sceneId, const IScene &scene) override;
    };

}