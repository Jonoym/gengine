#include <graphics/Texture.h>

namespace Gengine
{
    Texture::Texture(SDL_Texture* texture)
        : mTexture(texture)
    {
    }

    Texture::~Texture()
    {
    }

    void Texture::LoadFile(const std::string& filename)
    {
    }

    SDL_Texture* Texture::GetTexture()
    {
        return mTexture;
    }

    const Vector2D& Texture::GetSize()
    {
        return mSize;
    }
}