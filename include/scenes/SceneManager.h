#pragma once

#include <Includes.h>
#include <scenes/ISceneManager.h>

namespace Gengine
{

    class SceneManager : public ISceneManager
    {

    public:
        void ChangeScene(const std::string &sceneId) override;
        void AddScene(const std::string &sceneId, const IScene &scene) override;

    private:
    };

}