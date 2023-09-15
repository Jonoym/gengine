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
        void SetScreen(std::unique_ptr<IScreen> screen) override;

        void Dispose() override;

        void ChangeScreen(const std::string &screenId) override;
        void AddScreen(const std::string &screenId, const IScreen &screen) override;
    };

}