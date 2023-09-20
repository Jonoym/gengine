#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{

    bool ServiceManager::Update() {
        L_TRACE("[SERVICES]", "Starting Service Updates");

        uint32 currentTicks = mTimeManager.GetTotalTicks();

        L_TRACE("[SERVICES]", "Current Ticks: %d", currentTicks);
        mInputHandler.HandleInput();
        mTimeManager.Tick();
        mPhysicsService.Update();
        mEntityService.Update();
        mRenderService.Update();

        bool shouldQuit = mInputHandler.ShouldQuit();
        uint32 finalTicks = mTimeManager.GetTotalTicks();
        L_TRACE("[SERVICES]", "Final Ticks: %d", finalTicks);
        L_TRACE("[SERVICES]", "Difference: %d", finalTicks - currentTicks);

        return shouldQuit;
    }

    void ServiceManager::Dispose() {
        L_INFO("[SERVICES]", "Disposing Services");
        mRenderService.Dispose();
        mPhysicsService.Dispose();
        mEntityService.Dispose();
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

    TimeManager& ServiceManager::GetTimeManager() {
        return mTimeManager;
    }

}