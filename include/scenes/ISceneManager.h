#pragma once

#include <Includes.h>
#include <scenes/IScene.h>

namespace Gengine
{

    struct ISceneManager
    {

        virtual ~ISceneManager() {}

        virtual void ChangeScene(const std::string &sceneId) = 0;
        virtual void AddScene(const std::string &sceneId, const IScene &scene) = 0;
    };
}