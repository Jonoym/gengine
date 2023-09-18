#include <graphics/AnimateComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    AnimateComponent::AnimateComponent(const std::string &assetName, const std::string &path, const Vector2D &size)
        : mAssetName(assetName), mSize(size)
    {
        L_INFO("[ANIMATE COMPONENT]", "Creating Animate Component with Asset Name: %s at Path: %s", assetName.c_str(), path.c_str());
        Load(assetName, path);
    }
    AnimateComponent::AnimateComponent(const AnimateComponent &other) {}

    AnimateComponent::~AnimateComponent() {}

    void AnimateComponent::Load(const std::string &assetName, const std::string &path)
    {

        ServiceManager::GetServiceManager().GetRenderService().Register(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterAsset(assetName, path);

        mAnimations.emplace("default", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 16, 16, 16, false, false)
        }));
        mAnimations.emplace("defaultLeft", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 0, 16, 16, false, false)
        }));

        mAnimations.emplace("moveLeftStart", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 0, 16, 16, false, false),
            Box2D(16, 0, 16, 16, false, false),
            Box2D(32, 0, 16, 16, false, false),
            Box2D(48, 0, 16, 16, false, false)
        }));
        mAnimations.emplace("defaultRight", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 16, 16, 16, false, false)
        }));
        mAnimations.emplace("moveRightStart", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 16, 16, 16, false, false),
            Box2D(16, 16, 16, 16, false, false),
            Box2D(32, 16, 16, 16, false, false),
            Box2D(48, 16, 16, 16, false, false)
        }));

        mAnimations.emplace("defaultDown", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 32, 16, 16, false, false)
        }));
        mAnimations.emplace("moveDownStart", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 32, 16, 16, false, false),
            Box2D(16, 32, 16, 16, false, false),
            Box2D(32, 32, 16, 16, false, false),
            Box2D(48, 32, 16, 16, false, false)
        }));

        mAnimations.emplace("defaultUp", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 48, 16, 16, false, false)
        }));
        mAnimations.emplace("moveUpStart", std::make_pair(100, std::vector<Box2D>{
            Box2D(0, 48, 16, 16, false, false),
            Box2D(16, 48, 16, 16, false, false),
            Box2D(32, 48, 16, 16, false, false),
            Box2D(48, 48, 16, 16, false, false)
        }));
    }

    void AnimateComponent::AddAnimation(const std::string &animationName, uint32 delayTime)
    {

        L_INFO("[ANIMATE COMPONENT]", "Adding Animation");
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
            Vector2D(boundingRect.mX, boundingRect.mY)
        );
    }
}