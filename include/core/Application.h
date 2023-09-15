#pragma once

#include <Includes.h>
#include <gui/Interface.h>
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
        IInterface* mScreen = nullptr;
        std::unique_ptr<IGame> mGame = nullptr;
    };

}