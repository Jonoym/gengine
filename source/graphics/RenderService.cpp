#include <graphics/RenderService.h>
#include <core/Logger.h>

namespace Gengine
{
    RenderService::RenderService()
    {
        mRenderer = Interface::GetInterface().GetRenderer();
    }

    RenderService::~RenderService() {}

    void RenderService::Update()
    {
        L_TRACE("[RENDER SERVICE]", "Updating all Render Components");
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
        SDL_RenderClear(mRenderer);

        for (const auto& component: mRenderComponents)
        {
            L_TRACE("[RENDER SERVICE]", "Updating Render Component");
            component->Render();
        }

        SDL_RenderPresent(mRenderer);
    }

    void RenderService::Dispose()
    {
        L_INFO("[RENDER SERVICE]", "Disposing Assets");
        for (auto &asset : mAssets)
        {
            L_INFO("[RENDER SERVICE]", "Disposing Asset");
            SDL_DestroyTexture(asset.second);
        }

        mAssets.clear();
    }

    void RenderService::Render(const std::string &assetName, const Vector2D &position) {

        L_TRACE("[RENDER SERVICE]", "Attempting to Render Asset: %s", assetName.c_str());
        auto asset = mAssets.find(assetName);
        if (asset != nullptr) {
            L_TRACE("[RENDER SERVICE]", "Successfully Rendering Asset: %s", assetName.c_str());
            SDL_RenderCopy(mRenderer, asset->second, NULL, NULL);
        }
    }

    void RenderService::RegisterAsset(const std::string &assetName, const std::string &path)
    {

        L_INFO("[RENDER SERVICE]", "Registering Asset: %s", assetName.c_str());

        SDL_Surface *buffer = IMG_Load(path.c_str());
        if (!buffer)
        {
            L_ERROR("[RENDER SERVICE]", "Failed to Register Asset: %s", assetName.c_str());
            return;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, buffer);
        if (!texture)
        {
            L_ERROR("[RENDER SERVICE]", "Failed to Create Texture for Asset: %s", assetName.c_str());
            return;
        }
        SDL_FreeSurface(buffer);

        mAssets.emplace(assetName, texture);
    }

    void RenderService::Register(std::shared_ptr<Component> component)
    {
        mRenderComponents.push_back(std::static_pointer_cast<RenderComponent>(component));
    }
}