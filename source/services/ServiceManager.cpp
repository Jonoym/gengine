#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{

    bool ServiceManager::Update() {
        L_TRACE("[SERVICES]", "Starting Service Updates");

        mInputHandler.HandleInput();
        mPhysicsService.Update();
        mEntityService.Update();
        mRenderService.Update();

        bool shouldQuit = mInputHandler.ShouldQuit();

        return shouldQuit;
    }

    void ServiceManager::Dispose() {
        L_INFO("[SERVICES]", "Disposing Services");
        mEntityService.Dispose();
        mRenderService.Dispose();
    }

    EntityService& ServiceManager::GetEntityService() {
        return mEntityService;
    }

    RenderService& ServiceManager::GetRenderService() {
        return mRenderService;
    }

}