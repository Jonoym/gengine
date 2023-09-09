#include "RendererService.h"

RendererService::RendererService(SDL_Renderer* renderer)
    : mRenderer(renderer)
{}

RendererService::~RendererService() {
}

void RendererService::update()
{
    
}

void RendererService::dispose()
{
    for (auto it = mTextures.begin(); it != mTextures.end(); it++) {
        SDL_DestroyTexture(it->second);
    }
}

void RendererService::registerAsset(std::string assetName, const std::string& path) {
    SDL_Texture* texture = loadTexture(path);
    mTextures.emplace(std::make_pair(assetName, texture));
}

SDL_Texture* RendererService::loadTexture (const std::string& path) {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( mRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

SDL_Texture* RendererService::getAsset(const std::string& assetName) {

    auto it = mTextures.find(assetName);

    if (it != mTextures.end()) {
        return it->second;
    } else {
        return nullptr;
    }

    return nullptr;
}