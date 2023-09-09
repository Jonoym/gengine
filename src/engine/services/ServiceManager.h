#pragma once

#include <string>
#include "../timing/TimeService.h"
#include "../graphics/RendererService.h"

class ServiceManager
{

public:
    static ServiceManager& getServiceManager() {
        static ServiceManager serviceManager;
        return serviceManager;
    }

    ServiceManager (const ServiceManager&) = delete;
    ServiceManager& operator=(const ServiceManager&) = delete;

    void update();
    void dispose();

    void registerTimeService(TimeService* service);
    void registerRendererService(RendererService* service);

private:
    ServiceManager() {};
    ~ServiceManager() {};

    TimeService* mTimeService;
    RendererService* mRendererService;
};