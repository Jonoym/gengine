#include <screens/Screen.h>
#include <core/Logger.h>

#include <maps/Map.h>

namespace Gengine
{
    Screen::Screen() {}

    Screen::~Screen() {}

    void Screen::Initialise() {
        L_INFO("[SCREEN]", "Initialising Screen");

        mMap = std::make_unique<Map>();
        ServiceManager& serviceManager = ServiceManager::GetServiceManager();
        mServiceManager = &serviceManager;

        mServiceManager->Initialise();
        mMap->Initialise();
    }

    bool Screen::Update() {
        L_TRACE("[SCREEN]", "Starting Screen Update");
        
        bool shouldQuit = mServiceManager->Update();

        return shouldQuit;
    }

    void Screen::Dispose() {
        L_INFO("[SCREEN]", "Disposing Screen");
        mServiceManager->Dispose();
    }
}