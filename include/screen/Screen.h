#pragma once

#include <SDL2/SDL.h>

#include <screen/IScreen.h>

namespace Gengine
{
    class Screen : public IScreen
    {
    public:
        Screen();
        ~Screen();

        bool Initialise() override;
        void Exit() override;

    private:
        SDL_Window* mWindow;
    };
}