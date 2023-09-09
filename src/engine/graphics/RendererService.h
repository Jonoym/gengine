#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <unordered_map>
#include <string>

#include "../Types.h"

class RendererService {
public:

    RendererService(SDL_Renderer* renderer);
    ~RendererService();

    void update();
    void dispose();
    
    void registerAsset(std::string assetName, const std::string& path);

private:

    SDL_Renderer* mRenderer;

    SDL_Texture* loadTexture (const std::string& path);
    SDL_Texture* getAsset(const std::string& assetName);

    std::unordered_map<std::string, SDL_Texture*> mTextures;
};