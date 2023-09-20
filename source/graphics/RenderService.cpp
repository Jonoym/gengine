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

    void RenderService::OrderTextures()
    {
        std::sort(mRenderComponents.begin(), mRenderComponents.end(),
                  [](IRenderableComponent *a, IRenderableComponent *b)
                  {
                      return (b->mEntity->mPosition.mY + b->GetSize().mY / 2) > (a->mEntity->mPosition.mY + a->GetSize().mY / 2);
                  });
    }

    void RenderService::Dispose()
    {
        L_INFO("[RENDER SERVICE]", "Disposing Assets");
        for (auto &asset : mAssets)
        {
            L_INFO("[RENDER SERVICE]", "Disposing Asset: { '%s' }", asset.first.c_str());
            SDL_DestroyTexture(asset.second.GetTexture());
        }

        mAssets.clear();
    }

    void RenderService::Render(const std::string &assetName, const Vector2D &size, const Vector2D &position, const Vector2D &clipSize, const Vector2D &clipPosition)
    {
        L_TRACE("[RENDER SERVICE]", "Attempting to Render Asset: { '%s' }", assetName.c_str());
        auto asset = mAssets.find(assetName);
        if (asset != mAssets.end())
        {

            Box2D boundingRect(position.mX, position.mY, size.mX, size.mY, true, true);

            SDL_Rect dest = {
                static_cast<int>(boundingRect.mX),
                static_cast<int>(boundingRect.mY),
                static_cast<int>(boundingRect.mW),
                static_cast<int>(boundingRect.mH)};

            if (clipSize == Vector2D(0, 0) && clipPosition == Vector2D(0, 0))
            {
                L_TRACE("[RENDER SERVICE]", "Successfully Rendering Asset Size: { w: %f, h: %f }, Position: { x: %f, y: %f }",
                        boundingRect.mW, boundingRect.mH, boundingRect.mX, boundingRect.mY);
                SDL_RenderCopy(mRenderer, asset->second.GetTexture(), NULL, &dest);
            }
            else
            {
                L_TRACE("[RENDER SERVICE]", "Successfully Rendering Clip Texture Clip Size: { w: %f, h: %f }, Clip Position: { x: %f, y: %f }",
                        clipPosition.mX, clipPosition.mY, clipSize.mX, clipSize.mY);
                Box2D clipRect(clipPosition.mX, clipPosition.mY, clipSize.mX, clipSize.mY, false, false);

                SDL_Rect clip = {
                    static_cast<int>(clipRect.mX),
                    static_cast<int>(clipRect.mY),
                    static_cast<int>(clipRect.mW),
                    static_cast<int>(clipRect.mH)};

                SDL_RenderCopy(mRenderer, asset->second.GetTexture(), &clip, &dest);
            }
        }
    }

    void RenderService::RegisterAsset(const std::string &assetName, const std::string &path)
    {

        L_INFO("[RENDER SERVICE]", "Registering Asset: { '%s' }", assetName.c_str());

        auto asset = mAssets.find(assetName);
        if (asset != mAssets.end())
            return;

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

        mAssets.emplace(assetName, Texture(texture));
    }

    void RenderService::RegisterAnimation(const std::string &assetName, const std::string &path)
    {
        L_INFO("[RENDER SERVICE]", "Registering Animation File");
        std::vector<AtlasRegion> atlasRegions = AtlasReader::ParseAtlasFile(path);

        std::sort(atlasRegions.begin(), atlasRegions.end(), [](const AtlasRegion &a, const AtlasRegion &b)
                  { return (a.mAnimationName != b.mAnimationName) ? a.mAnimationName < b.mAnimationName : a.mIndex < b.mIndex; });

        std::unordered_map<std::string, std::vector<Box2D>> mAnimationClips;

        for (auto &atlasRegion : atlasRegions)
        {
            L_INFO("[RENDER SERVICE]", "Atlas Regions with Name: %s, Position: { %d, %d }", atlasRegion.mAnimationName.c_str(), atlasRegion.mLocation.mX, atlasRegion.mLocation.mY);
            auto it = mAnimationClips.find(atlasRegion.mAnimationName);
            if (it == mAnimationClips.end())
            {
                mAnimationClips.emplace(
                    atlasRegion.mAnimationName,
                    std::vector<Box2D>({Box2D(atlasRegion.mLocation.mX, atlasRegion.mLocation.mY, atlasRegion.mSize.mX, atlasRegion.mSize.mY)}));
            }
            else
            {
                it->second.push_back(Box2D(atlasRegion.mLocation.mX, atlasRegion.mLocation.mY, atlasRegion.mSize.mX, atlasRegion.mSize.mY));
            }
        }

        mSpritesheets.emplace(assetName, mAnimationClips);
    }

    std::vector<Box2D> *RenderService::GetAnimation(const std::string &assetName, const std::string &animationName)
    {
        L_INFO("[RENDER SERVICE]", "Retrieving the Animation frames for Asset: '%s'", assetName.c_str());
        auto spritesheet = mSpritesheets.find(assetName);
        if (spritesheet == nullptr)
        {
            L_WARN("[RENDER SERVICE]", "Unable to find Spritesheet File with Name: '%s'", assetName.c_str());
            return nullptr;
        }

        auto animation = spritesheet->second.find(animationName);

        if (animation == nullptr)
        {
            L_WARN("[RENDER SERVICE]", "Unable to find Animation with Name: '%s'", animationName.c_str());
            return nullptr;
        }

        return &animation->second;
    }

    void RenderService::Register(IRenderableComponent *component)
    {
        L_INFO("[RENDER SERVICE]", "Registering Render Component");
        mRenderComponents.push_back(component);
    }
}