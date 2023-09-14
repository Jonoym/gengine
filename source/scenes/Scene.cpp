#include <scenes/Scene.h>
#include <core/Logger.h>

#include <maps/Map.h>

namespace Gengine
{
    Scene::Scene() {}

    Scene::~Scene() {}

    void Scene::Initialise() {
        L_INFO("[SCENE]", "Initialising Scene");

        mMap = std::make_unique<Map>();
        ServiceManager& serviceManager = ServiceManager::getServiceManager();
        mServiceManager = &serviceManager;
    }

    bool Scene::Update() {
        L_INFO("[SCENE]", "Starting Scene Update");
        
        bool shouldQuit = mServiceManager->Update();

        return shouldQuit;
    }

    void Scene::Dispose() {
        L_INFO("[SCENE]", "Disposing Scene");

    }
}