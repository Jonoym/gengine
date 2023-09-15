#pragma once

#include <Includes.h>
#include <maps/IMap.h>
#include <services/ServiceManager.h>

namespace Gengine {

    struct IScreen {

        virtual void Initialise() = 0;
        virtual bool Update() = 0;
        virtual void Dispose() = 0;

        std::unique_ptr<IMap> mMap = nullptr;
        ServiceManager* mServiceManager = nullptr;
    };
}