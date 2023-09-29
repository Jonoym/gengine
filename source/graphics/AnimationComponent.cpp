#include <graphics/AnimationComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
        AnimationComponent::AnimationComponent(const std::string &assetName,
                           const std::string &texturePath,
                           const std::string &atlasPath,
                           const Vector2D &size,
                           RenderPriority priority,
                           const Vector2D &offset,
                           const std::string &defaultName)
        : IRenderableComponent(priority, size)
        , IDebugRenderableComponent(DebugColour::BLUE, BoundType::RECTANGLE)
        , mAssetName(assetName)
        , mOffset(offset)
        , mDefaultName(defaultName)
    {
        L_INFO("[ANIMATE COMPONENT]", "Creating Animate Component with Asset Name: '%s' at Texture Path: '%s' Atlas Path: '%s' ", assetName.c_str(), texturePath.c_str(), atlasPath.c_str());
        ServiceManager::GetServiceManager().GetRenderService().Register(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterDebug(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterAsset(assetName, texturePath);
        ServiceManager::GetServiceManager().GetRenderService().RegisterAnimation(assetName, atlasPath);

        AddAnimation(defaultName, AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
    }
    AnimationComponent::AnimationComponent(const AnimationComponent &other)
        : IRenderableComponent(other.mPriority, other.mSize)
        , IDebugRenderableComponent(DebugColour::BLUE, BoundType::RECTANGLE)
    {}

    AnimationComponent::~AnimationComponent() {}

    void AnimationComponent::Dispose()
    {
        ServiceManager::GetServiceManager().GetRenderService().Deregister(this);
        ServiceManager::GetServiceManager().GetRenderService().DeregisterDebug(this);
    }

    void AnimationComponent::Create()
    {
        L_INFO("[ANIMATE COMPONENT]", "Starting Animation with Name: '%s'", mDefaultName.c_str());
        StartAnimation(mDefaultName, false);
    }

    void AnimationComponent::AddAnimation(const std::string &animationName, AnimationPlaythrough playthrough, AnimationCompletion completion, uint32 delayTime)
    {
        L_INFO("[ANIMATE COMPONENT]", "Adding Animation with Name: '%s' and Delay Time: { %d } ", animationName.c_str(), delayTime);

        const auto &animationFrames = ServiceManager::GetServiceManager().GetRenderService().GetAnimation(mAssetName, animationName);

        if (animationFrames == nullptr)
        {
            L_INFO("[ANIMATE COMPONENT]", "Could not add the Animation for: '%s'", animationName.c_str());
        }

        mAnimations.emplace(animationName, AnimationPlayInfo{playthrough, completion, delayTime});
    }

    void AnimationComponent::StartAnimation(const std::string &animationName, bool force)
    {
        L_TRACE("[ANIMATE COMPONENT]", "Attempting to Start Animation with Name: %s", animationName.c_str());
        auto it = mAnimations.find(animationName);
        if (it == nullptr)
        {
            L_WARN("[ANIMATE COMPONENT]", "Failed to Start and Find Animation with Name: %s", animationName.c_str());
            return;
        }

        const auto &animationFrames = ServiceManager::GetServiceManager().GetRenderService().GetAnimation(mAssetName, animationName);

        AnimationCompletion completion = mCurrentAnimation.mAnimationInfo.mCompletion;

        if (force || (completion == AnimationCompletion::COMPLETE && mCurrentAnimation.mComplete)
            || (completion != AnimationCompletion::COMPLETE && animationName != mCurrentAnimation.mAnimationName))
        {
            L_TRACE("[ANIMATE COMPONENT]", "Starting Animation with Name: %s", animationName.c_str());
            mCurrentAnimation.mStartTime = ServiceManager::GetServiceManager().GetTimeManager().GetTicks();
            mCurrentAnimation.mFrameIndex = 0;
            mCurrentAnimation.mAnimationName = animationName;
            mCurrentAnimation.mAnimationFrames = animationFrames;
            mCurrentAnimation.mAnimationInfo = it->second;
            mCurrentAnimation.mComplete = false;
        }
    }

    void AnimationComponent::Render()
    {
        L_TRACE("[ANIMATE COMPONENT]", "Rendering Component");

        UpdateAnimation();

        L_TRACE("[ANIMATE COMPONENT]", "Rendering Current Frame");
        Box2D boundingRect = mCurrentAnimation.mAnimationFrames->at(mCurrentAnimation.mFrameIndex);
        L_TRACE("[ANIMATE COMPONENT]", "Bounding Rectangle for Animation: { x: %d, y: %d, w: %d, h: %d }", boundingRect.mX, boundingRect.mY, boundingRect.mW, boundingRect.mH);
        ServiceManager::GetServiceManager().GetRenderService().Render(
            mAssetName, mSize, mEntity->GetPosition() + mOffset, mPriority,
            Vector2D(boundingRect.mW, boundingRect.mH),
            Vector2D(boundingRect.mX, boundingRect.mY));
    }

    void AnimationComponent::UpdateAnimation()
    {
        uint32 currentTime = ServiceManager::GetServiceManager().GetTimeManager().GetTicks();
        if (mCurrentAnimation.mStartTime + mCurrentAnimation.mAnimationInfo.mFrameDelay < currentTime)
        {
            L_TRACE("[ANIMATE COMPONENT]", "Updating Current Frame");
            mCurrentAnimation.mStartTime = currentTime;
            switch (mCurrentAnimation.mAnimationInfo.mPlaythrough)
            {
            case AnimationPlaythrough::NORMAL:
                if (mCurrentAnimation.mFrameIndex + 1 == mCurrentAnimation.mAnimationFrames->size())
                {
                    mCurrentAnimation.mComplete = true;
                    break;
                }
            case AnimationPlaythrough::LOOP:
                mCurrentAnimation.mFrameIndex = (mCurrentAnimation.mFrameIndex + 1) % mCurrentAnimation.mAnimationFrames->size();
                break;
            }
        }
    }

    void AnimationComponent::RenderDebug()
    {
        ServiceManager::GetServiceManager().GetRenderService().RenderDebug(
            mColour, mBoundType, Box2D(mEntity->mPosition + mOffset, mSize, true, true), mPriority
        );
    }
}