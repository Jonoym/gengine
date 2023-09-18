#include <graphics/RenderService.h>
#include <utils/Box2D.h>
#include <core/Logger.h>
#include <entities/Entity.h>
#include <algorithm>

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

        OrderTextures();

        for (const auto &component : mRenderComponents)
        {
            L_TRACE("[RENDER SERVICE]", "Updating Render Component");
            component->Render();
        }

        SDL_RenderPresent(mRenderer);
    }

    void RenderService::OrderTextures() {
        std::sort(mRenderComponents.begin(), mRenderComponents.end(),
            [](RenderComponent* a, RenderComponent* b) {
                return (b->mEntity->mPosition.mY + b->GetSize().mY / 2) > (a->mEntity->mPosition.mY + a->GetSize().mY / 2);
            }
        );
    }

    void RenderService::Dispose()
    {
        L_INFO("[RENDER SERVICE]", "Disposing Assets");
        for (auto &asset : mAssets)
        {
            L_INFO("[RENDER SERVICE]", "Disposing Asset: { '%s' }", asset.first.c_str());
            SDL_DestroyTexture(asset.second);
        }

        mAssets.clear();
    }

    void RenderService::Render(const std::string &assetName, const Vector2D &size, const Vector2D &position)
    {

        L_TRACE("[RENDER SERVICE]", "Attempting to Render Asset: { '%s' }", assetName.c_str());
        auto asset = mAssets.find(assetName);
        if (asset != mAssets.end())
        {

            Box2D boundingRect(position.mX, position.mY, size.mX, size.mY);

            SDL_Rect dest = {
                static_cast<int>(boundingRect.mX),
                static_cast<int>(boundingRect.mY),
                static_cast<int>(boundingRect.mW),
                static_cast<int>(boundingRect.mH)
            };
            L_TRACE("[RENDER SERVICE]", "Successfully Rendering Asset Size: { w: %f, h: %f }, Position: { x: %f, y: %f }",
                boundingRect.mW, boundingRect.mH, boundingRect.mX, boundingRect.mY);

            SDL_RenderCopy(mRenderer, asset->second, NULL, &dest);
        }
    }

    void RenderService::RegisterAsset(const std::string &assetName, const std::string &path)
    {

        L_INFO("[RENDER SERVICE]", "Registering Asset: { '%s' }", assetName.c_str());

        auto asset = mAssets.find(assetName);
        if (asset != mAssets.end()) return;

        SDL_Surface *buffer = IMG_Load(path.c_str());
        if (!buffer)
        {
            L_ERROR("[RENDER SERVICE]", "Failed to Register Asset: { '%s' }", assetName.c_str());
            return;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, buffer);
        if (!texture)
        {
            L_ERROR("[RENDER SERVICE]", "Failed to Create Texture for Asset: { %s }", assetName.c_str());
            return;
        }
        SDL_FreeSurface(buffer);

        mAssets.emplace(assetName, texture);
    }

    void RenderService::Register(RenderComponent* component)
    {
        L_INFO("[INPUT HANDLER]", "Registering Render Component");
        mRenderComponents.push_back(component);
    }
}