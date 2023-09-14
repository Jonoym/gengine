#pragma once

#include <Includes.h>
#include <physics/PhysicsService.h>
#include <graphics/RenderService.h>
#include <entities/EntityService.h>
#include <timing/TimeManager.h>
#include <input/InputHandler.h>

namespace Gengine
{

    class ServiceManager
    {
    
    public:

        static ServiceManager& getServiceManager() {
            static ServiceManager serviceManager;
            return serviceManager;
        }

        ServiceManager (const ServiceManager&) = delete;
        ServiceManager& operator=(const ServiceManager&) = delete;

        bool Update();
        void Dispose();

        EntityService& GetEntityService();

    private:

        ServiceManager() {};
        ~ServiceManager() {};

        PhysicsService mPhysicsService;
        RenderService mRenderService;
        EntityService mEntityService;
        TimeManager mTimeManager;
        InputHandler mInputHandler;
    };
}