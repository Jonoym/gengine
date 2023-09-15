#pragma once

#include <Includes.h>
#include <screens/IScreen.h>

namespace Gengine
{

    struct IGame
    {

        virtual ~IGame() {}

        virtual void Initialise() = 0;
        virtual void MainLoop() = 0;
        virtual void SetScreen(std::unique_ptr<IScreen> screen) = 0;

        virtual void Dispose() = 0;
        
        virtual void ChangeScreen(const std::string &screenId) = 0;
        virtual void AddScreen(const std::string &screenId, const IScreen &screen) = 0;

        std::unique_ptr<IScreen> mScreen = nullptr;
    };
}