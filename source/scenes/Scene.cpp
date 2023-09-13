#include <scenes/Scene.h>
#include <core/Logger.h>

namespace Gengine
{
    Scene::Scene() {}

    Scene::~Scene() {}

    void Scene::Initialise() {
        L_INFO("[SCENE]", "Initialising Scene");

        mPhysicsService = std::make_unique<PhysicsService>();
        mRenderService = std::make_unique<RenderService>();
        mEntityService = std::make_unique<EntityService>();
    }

    void Scene::Update() {
        L_INFO("[SCENE]", "Starting Scene Update");

        mPhysicsService->Update();

        mRenderService->Update();

        mEntityService->Update();
    }

    void Scene::Dispose() {}
}