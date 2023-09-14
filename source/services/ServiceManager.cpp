#include <services/ServiceManager.h>

namespace Gengine
{
    ServiceManager::ServiceManager() {}
    ServiceManager::~ServiceManager() {}

    bool ServiceManager::Update() {
        
        mInputHandler.HandleInput();
        mPhysicsService.Update();
        mEntityService.Update();
        mRenderService.Update();

        bool shouldQuit = mInputHandler.ShouldQuit();

        return shouldQuit;
    }
    void ServiceManager::Dispose() {}
}