#pragma once

#include <Includes.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class Texture
    {
    public:
        Texture(SDL_Texture* texture);
        ~Texture();

        void LoadFile(const std::string& filename);
        const Vector2D& GetSize();

        SDL_Texture* GetTexture();

    private:
        SDL_Texture *mTexture;

        Vector2D mSize;
    };
}