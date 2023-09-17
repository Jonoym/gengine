#include <SDL2/SDL.h>

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
        mScreen = &interface;

        mGame = std::make_unique<Gengine::Game>();
    }

    void Application::Run()
    {
        L_INFO("[APPLICATION]", "Running the Application");
        if (!mScreen->Initialise()) {
            return;
        }

        L_INFO("[APPLICATION]", "Screen Initialised Successfully");

        mGame->Initialise();

        mGame->MainLoop();

        mGame->Dispose();

        mScreen->Exit();
    }

}