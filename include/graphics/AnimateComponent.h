#pragma once

#include <graphics/IRenderableComponent.h>

#include <components/Component.h>
#include <utils/Vector2D.h>
#include <utils/Box2D.h>

namespace Gengine
{
    enum class AnimationPlaythrough
    {
        LOOP,
        NORMAL
    };

    enum class AnimationCompletion
    {
        COMPLETE,
        CANCELLABLE
    };

    struct AnimationPlayInfo
    {
        AnimationPlaythrough mPlaythrough = AnimationPlaythrough::NORMAL;
        AnimationCompletion mCompletion = AnimationCompletion::CANCELLABLE;
        uint32 mFrameDelay;
    };
    struct AnimationFrame

    {
        std::string mAnimationName = "";
        uint32 mStartTime = 0;
        uint8 mFrameIndex = 0;
        std::vector<Box2D> *mAnimationFrames;
        AnimationPlayInfo mAnimationInfo;
        bool mComplete = false;
    };

    class AnimateComponent : public IRenderableComponent
    {
    public:
        AnimateComponent(const std::string &assetName, const std::string &texturePath, const std::string &atlasPath, const Vector2D &size, RenderPriority priority);
        AnimateComponent(const AnimateComponent &other);
        ~AnimateComponent();

        void AddAnimation(const std::string &animationName, AnimationPlaythrough playthrough, AnimationCompletion completion, uint32 delayTime);
        void StartAnimation(const std::string &animationName, bool force);

        const Vector2D &GetSize() override;
        void UpdateSize(const Vector2D &size);

        void Render() override;
        Vector2D mSize;

    private:
        std::string mAssetName;
        std::unordered_map<std::string, AnimationPlayInfo> mAnimations;
        AnimationFrame mCurrentAnimation;
    };
}