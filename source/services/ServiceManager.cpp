#include <services/ServiceManager.h>

namespace Gengine
{

    bool ServiceManager::Update() {
        
        mInputHandler.HandleInput();
        mPhysicsService.Update();
        mEntityService.Update();
        mRenderService.Update();

        bool shouldQuit = mInputHandler.ShouldQuit();

        return shouldQuit;
    }

    void ServiceManager::Dispose() {
        mEntityService.Dispose();
    }

    EntityService& ServiceManager::GetEntityService() {
        return mEntityService;
    }

}