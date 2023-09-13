#pragma once

#include <Includes.h>
#include <screen/Screen.h>
#include <game/Game.h>

namespace Gengine
{

    class Application
    {

    public:
        Application();
        ~Application();

        void Initialise();

        void Run();

    private:
        std::unique_ptr<IScreen> mScreen = nullptr;
        std::unique_ptr<IGame> mGame = nullptr;
    };

}