#pragma once

#include <Includes.h>
#include <screens/IScreen.h>

namespace Gengine
{

    class Game
    {

    public:

        Game();
        ~Game();

        void Initialise();
        void MainLoop();
        void SetScreen(std::unique_ptr<IScreen> screen);

        void Dispose();

        void ChangeScreen(const std::string &screenId);
        void AddScreen(const std::string &screenId, const IScreen &screen);

    private:
        std::unique_ptr<IScreen> mScreen = nullptr;
    };

}