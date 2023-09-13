#pragma once

#include <Includes.h>
#include <physics/PhysicsService.h>
#include <graphics/RenderService.h>
#include <entities/EntityService.h>

namespace Gengine {

    struct IScene {

        virtual void Initialise() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

        std::unique_ptr<PhysicsService> mPhysicsService = nullptr;
        std::unique_ptr<RenderService> mRenderService = nullptr;
        std::unique_ptr<EntityService> mEntityService = nullptr;
    };
}