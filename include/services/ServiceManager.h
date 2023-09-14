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
        ServiceManager();
        ~ServiceManager();

        bool Update();
        void Dispose();

    private:
        PhysicsService mPhysicsService;
        RenderService mRenderService;
        EntityService mEntityService;
        TimeManager mTimeManager;
        InputHandler mInputHandler;
    };
}