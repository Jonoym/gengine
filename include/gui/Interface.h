#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <gui/IInterface.h>

namespace Gengine
{
    class Interface : public IInterface
    {
    public:

        static Interface& GetInterface() {
            static Interface interface;
            return interface;
        }

        Interface (const Interface&) = delete;
        Interface& operator=(const Interface&) = delete;

        bool Initialise() override;
        void Exit() override;

        SDL_Window* GetWindow();
        SDL_Renderer* GetRenderer();

    private:
        Interface();
        ~Interface();

        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
    };
}