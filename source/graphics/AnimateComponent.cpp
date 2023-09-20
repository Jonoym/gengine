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
        ServiceManager::GetServiceManager().GetRenderService().RegisterAnimation(assetName, atlasPath);
    }
    AnimateComponent::AnimateComponent(const AnimateComponent &other) {}

    AnimateComponent::~AnimateComponent() {}

    void AnimateComponent::AddAnimation(const std::string &animationName, uint32 delayTime, AnimationPlaythrough playthrough)
    {
        L_INFO("[ANIMATE COMPONENT]", "Adding Animation with Name: '%s' and Delay Time: { %d } ", animationName.c_str(), delayTime);

        const auto &animationFrames = ServiceManager::GetServiceManager().GetRenderService().GetAnimation(mAssetName, animationName);

        if (animationFrames == nullptr)
        {
            L_INFO("[ANIMATE COMPONENT]", "Could not add the Animation for: '%s'", animationName.c_str());
        }

        mAnimations.emplace(animationName, AnimationPlayInfo{playthrough, delayTime});
    }

    void AnimateComponent::StartAnimation(const std::string &animationName, bool force)
    {
        L_INFO("[ANIMATE COMPONENT]", "Starting Animation with Name: %s", animationName.c_str());
        auto it = mAnimations.find(animationName);
        if (it == nullptr)
        {
            L_WARN("[ANIMATE COMPONENT]", "Failed to Start and Find Animation with Name: %s", animationName.c_str());
            return;
        }

        const auto &animationFrames = ServiceManager::GetServiceManager().GetRenderService().GetAnimation(mAssetName, animationName);

        if (animationName != mCurrentAnimation.mAnimationName || force)
        {
            mCurrentAnimation.mStartTime = ServiceManager::GetServiceManager().GetTimeManager().GetTotalTicks();
            mCurrentAnimation.mFrameIndex = 0;
            mCurrentAnimation.mAnimationName = animationName;
            mCurrentAnimation.mAnimationFrames = animationFrames;
            mCurrentAnimation.mAnimationInfo = it->second;
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
        if (mCurrentAnimation.mStartTime + mCurrentAnimation.mAnimationInfo.mFrameDelay < currentTime)
        {
            L_TRACE("[ANIMATE COMPONENT]", "Updating Current Frame");
            mCurrentAnimation.mStartTime = currentTime;
            switch (mCurrentAnimation.mAnimationInfo.mPlaythrough)
            {
            case AnimationPlaythrough::NORMAL:
                if (mCurrentAnimation.mFrameIndex + 1 == mCurrentAnimation.mAnimationFrames->size())
                {
                    break;
                }
            case AnimationPlaythrough::LOOP:
                mCurrentAnimation.mFrameIndex = (mCurrentAnimation.mFrameIndex + 1) % mCurrentAnimation.mAnimationFrames->size();
                break;
            }
        }
        L_TRACE("[ANIMATE COMPONENT]", "Rendering Current Frame");
        Box2D boundingRect = mCurrentAnimation.mAnimationFrames->at(mCurrentAnimation.mFrameIndex);
        ServiceManager::GetServiceManager().GetRenderService().Render(
            mAssetName, mSize, mEntity->GetPosition(),
            Vector2D(boundingRect.mW, boundingRect.mH),
            Vector2D(boundingRect.mX, boundingRect.mY));
    }
}