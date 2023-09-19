#include <graphics/AnimateComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    AnimateComponent::AnimateComponent(const std::string &assetName, const std::string &texturePath, const std::string &atlasPath, const Vector2D &size)
        : mAssetName(assetName), mSize(size)
    {
        L_INFO("[ANIMATE COMPONENT]", "Creating Animate Component with Asset Name: '%s' at Texture Path: '%s' Atlas Path: '%s' ", assetName.c_str(), texturePath.c_str(), atlasPath.c_str());
        ServiceManager::GetServiceManager().GetRenderService().Register(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterAsset(assetName, texturePath);
        Load(atlasPath);
    }
    AnimateComponent::AnimateComponent(const AnimateComponent &other) {}

    AnimateComponent::~AnimateComponent() {}

    void AnimateComponent::Load(const std::string &atlasPath)
    {
        std::vector<AtlasRegion> atlasRegions = AtlasReader::ParseAtlasFile(atlasPath);

        std::sort(atlasRegions.begin(), atlasRegions.end(), [](const AtlasRegion &a, const AtlasRegion &b)
                  { return (a.mAnimationName != b.mAnimationName) ? a.mAnimationName < b.mAnimationName : a.mIndex < b.mIndex; });

        for (auto &atlasRegion : atlasRegions)
        {
            L_INFO("[ANIMATE COMPONENT]", "Atlas Regions with Name: %s, Position: { %d, %d }", atlasRegion.mAnimationName.c_str(), atlasRegion.mLocation.mX, atlasRegion.mLocation.mY);
            auto it = mAnimations.find(atlasRegion.mAnimationName);
            if (it == mAnimations.end())
            {
                mAnimations.emplace(atlasRegion.mAnimationName, std::make_pair(
                    100, std::vector<Box2D>({
                        Box2D(atlasRegion.mLocation.mX, atlasRegion.mLocation.mY, atlasRegion.mSize.mX, atlasRegion.mSize.mY)
                    })
                ));
            }
            else
            {
                it->second.second.push_back(Box2D(atlasRegion.mLocation.mX, atlasRegion.mLocation.mY, atlasRegion.mSize.mX, atlasRegion.mSize.mY));
            }
        }
    }

    void AnimateComponent::AddAnimation(const std::string &animationName, uint32 delayTime)
    {
        L_INFO("[ANIMATE COMPONENT]", "Adding Animation with Name: '%s' and Delay Time: { %d } ", delayTime);
        auto it = mAnimations.find(animationName);

        if (it != nullptr)
        {
            it->second.first = delayTime;
        }
        else
        {
            L_INFO("[ANIMATE COMPONENT]", "Failed to Add Animation for the Animation Reference");
        }
    }

    void AnimateComponent::StartAnimation(const std::string &animationName, bool force)
    {
        L_INFO("[ANIMATE COMPONENT]", "Starting Animation with Name: %s", animationName.c_str());
        auto it = mAnimations.find(animationName);
        if (it == nullptr)
        {
            L_INFO("[ANIMATE COMPONENT]", "Failed to Start and Find Animation with Name: %s", animationName.c_str());
            return;
        }

        if (animationName != mCurrentAnimation.mAnimationName || force)
        {
            mCurrentAnimation.mStartTime = ServiceManager::GetServiceManager().GetTimeManager().GetTotalTicks();
            mCurrentAnimation.mFrameIndex = 0;
            mCurrentAnimation.mAnimationName = animationName;
            mCurrentAnimation.mDelayTime = it->second.first;
            mCurrentAnimation.mAnimationFrames = &it->second.second;
        }
    }

    void AnimateComponent::UpdateSize(const Vector2D &size)
    {
        mSize = size;
    }

    const Vector2D &AnimateComponent::GetSize()
    {
        return mSize;
    }

    void AnimateComponent::Render()
    {
        L_TRACE("[ANIMATE COMPONENT]", "Rendering Component");
        uint32 currentTime = ServiceManager::GetServiceManager().GetTimeManager().GetTotalTicks();
        L_TRACE("[ANIMATE COMPONENT]", "Current Time: %d", currentTime);
        L_TRACE("[ANIMATE COMPONENT]", "Delay Time: %d", mCurrentAnimation.mDelayTime);
        L_TRACE("[ANIMATE COMPONENT]", "Start Time: %d", mCurrentAnimation.mStartTime);

        if (mCurrentAnimation.mStartTime + mCurrentAnimation.mDelayTime < currentTime)
        {
            mCurrentAnimation.mStartTime = currentTime;
            mCurrentAnimation.mFrameIndex = (mCurrentAnimation.mFrameIndex + 1) % mCurrentAnimation.mAnimationFrames->size();
        }

        Box2D boundingRect = mCurrentAnimation.mAnimationFrames->at(mCurrentAnimation.mFrameIndex);

        ServiceManager::GetServiceManager().GetRenderService().Render(
            mAssetName, mSize, mEntity->GetPosition(),
            Vector2D(boundingRect.mW, boundingRect.mH),
            Vector2D(boundingRect.mX, boundingRect.mY));
    }
}