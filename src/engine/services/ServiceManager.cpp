#include "ServiceManager.h"

void ServiceManager::registerRendererService(RendererService* service)
{
    mRendererService = service;
}

void ServiceManager::registerTimeService(TimeService* service)
{
    mTimeService = service;
}

void ServiceManager::update() {
    mRendererService->update();
}

void ServiceManager::dispose()
{
    delete mTimeService;
    delete mRendererService;
}