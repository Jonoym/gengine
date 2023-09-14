#include <scenes/Scene.h>
#include <core/Logger.h>

namespace Gengine
{
    Scene::Scene() : counter(0) {}

    Scene::~Scene() {}

    void Scene::Initialise() {
        L_INFO("[SCENE]", "Initialising Scene");
    }

    bool Scene::Update() {
        L_INFO("[SCENE]", "Starting Scene Update");

        bool shouldQuit = mServiceManager.Update();

        return shouldQuit;
    }

    void Scene::Dispose() {
        L_INFO("[SCENE]", "Disposing Scene");

    }
}