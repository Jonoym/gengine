#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{

    bool ServiceManager::Update() {
        L_TRACE("[SERVICES]", "Starting Service Updates");

        mInputHandler.HandleInput();
        mTimeManager.Tick();
        mPhysicsService.Update(mTimeManager.GetDeltaTime());
        mEntityService.Update();
        mRenderService.Update();

        bool shouldQuit = mInputHandler.ShouldQuit();

        return shouldQuit;
    }

    void ServiceManager::Dispose() {
        L_INFO("[SERVICES]", "Disposing Services");
        mEntityService.Dispose();
        mRenderService.Dispose();
        mPhysicsService.Dispose();
    }

    EntityService& ServiceManager::GetEntityService() {
        return mEntityService;
    }

    RenderService& ServiceManager::GetRenderService() {
        return mRenderService;
    }

    InputHandler& ServiceManager::GetInputHandler() {
        return mInputHandler;
    }

    PhysicsService& ServiceManager::GetPhysicsService() {
        return mPhysicsService;
    }

}