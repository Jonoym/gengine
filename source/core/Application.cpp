#include <core/Application.h>
#include <core/Logger.h>

namespace Gengine
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }
    
    void Application::Initialise()
    {
        L_INFO("[APPLICATION]", "Initialising Application")

        Interface& interface = Interface::GetInterface();
        mInterface = &interface;

        mGame = std::make_unique<Gengine::Game>();
    }

    void Application::Run()
    {
        L_INFO("[APPLICATION]", "Running the Application");
        if (!mInterface->Initialise()) {
            return;
        }

        L_INFO("[APPLICATION]", "Screen Initialised Successfully");

        mGame->Initialise();

        mGame->MainLoop();

        mGame->Dispose();

        mInterface->Exit();
    }

}