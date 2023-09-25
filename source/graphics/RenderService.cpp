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

        for (const auto &component : mDebugComponents)
        {
            L_TRACE("[RENDER SERVICE]", "Updating Debug Render Component");
            component->RenderDebug();
        }

        SDL_RenderPresent(mRenderer);
    }

    void RenderService::OrderTextures()
    {
        std::sort(mRenderComponents.begin(), mRenderComponents.end(),
                  [](IRenderableComponent *a, IRenderableComponent *b)
                  {
                      if (a->mPriority == b->mPriority)
                      {
                          return (b->mEntity->mPosition.mY + b->mSize.mY / 2) > (a->mEntity->mPosition.mY + a->mSize.mY / 2);
                      }
                      else
                      {
                          return a->mPriority < b->mPriority;
                      }
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
        L_TRACE("[RENDER SERVICE]", "Attempting to Render Asset: { '%s' } with Size: { w: %f, h: %f } at Position: { x: %f, y: %f }", assetName.c_str(), size.mX, size.mY, position.mX, position.mY);
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

    void RenderService::RenderDebug(DebugColour lineColour, BoundType boundType, const Box2D &bounds)
    {
        switch (lineColour)
        {
        case DebugColour::RED:
            SDL_SetRenderDrawColor(mRenderer, 0xFF, 0x00, 0x00, 0xFF);
            break;
        case DebugColour::GREEN:
            SDL_SetRenderDrawColor(mRenderer, 0x00, 0xFF, 0x00, 0xFF);
            break;
        case DebugColour::BLUE:
            SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0xFF, 0xFF);
            break;
        }

        switch (boundType)
        {
        case BoundType::CIRCULAR:
            RenderCircle(bounds);
            break;
        case BoundType::RECTANGLE:
            SDL_Rect outlineRect = {bounds.mX, bounds.mY, bounds.mW, bounds.mH};
            SDL_RenderDrawRect(mRenderer, &outlineRect);
            break;
        }
    }

    void RenderService::RenderCircle(const Box2D &bounds)
    {
        const int32 diameter = (bounds.mH);

        int32_t x = (diameter / 2 - 1);
        int32_t y = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);

        while (x >= y)
        {
            SDL_RenderDrawPoint(mRenderer, bounds.mX + x, bounds.mY - y);
            SDL_RenderDrawPoint(mRenderer, bounds.mX + x, bounds.mY + y);
            SDL_RenderDrawPoint(mRenderer, bounds.mX - x, bounds.mY - y);
            SDL_RenderDrawPoint(mRenderer, bounds.mX - x, bounds.mY + y);
            SDL_RenderDrawPoint(mRenderer, bounds.mX + y, bounds.mY - x);
            SDL_RenderDrawPoint(mRenderer, bounds.mX + y, bounds.mY + x);
            SDL_RenderDrawPoint(mRenderer, bounds.mX - y, bounds.mY - x);
            SDL_RenderDrawPoint(mRenderer, bounds.mX - y, bounds.mY + x);

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
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
        L_TRACE("[RENDER SERVICE]", "Retrieving the Animation frames for Asset: '%s'", assetName.c_str());
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

    void RenderService::RegisterDebug(IDebugRenderableComponent *component)
    {
        L_INFO("[RENDER SERVICE]", "Registering Debu Render Component");
        mDebugComponents.push_back(component);
    }

}