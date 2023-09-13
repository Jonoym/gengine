#include <core/Application.h>
#include <core/Logger.h>

#include <SDL2/SDL.h>

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
        L_INFO("[APPLICATION]", "Initialising Application");
        mScreen = std::make_unique<Gengine::Screen>();
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

        mScreen->Exit();
    }

}