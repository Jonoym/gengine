#pragma once

#include <Includes.h>
#include <scenes/IScene.h>

namespace Gengine
{

    struct IGame
    {

        virtual ~IGame() {}

        virtual void Initialise() = 0;
        virtual void MainLoop() = 0;
        virtual void SetScene(std::unique_ptr<IScene> scene) = 0;

        virtual void Dispose() = 0;
        
        // virtual void ChangeScene(const std::string &sceneId) = 0;
        // virtual void AddScene(const std::string &sceneId, const IScene &scene) = 0;

        std::unique_ptr<IScene> mScene = nullptr;
    };
}