#pragma once

#include <graphics/IRenderableComponent.h>
#include <graphics/IDebugRenderableComponent.h>
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

    class AnimationComponent : public IRenderableComponent, IDebugRenderableComponent
    {
    public:
        AnimationComponent(const std::string &assetName,
                           const std::string &texturePath,
                           const std::string &atlasPath,
                           const Vector2D &size,
                           RenderPriority priority,
                           const Vector2D &offset = Vector2D(),
                           const std::string &defaultName = "default");
        AnimationComponent(const AnimationComponent &other);
        ~AnimationComponent();

        virtual void Create() override;
        void AddAnimation(const std::string &animationName, AnimationPlaythrough playthrough, AnimationCompletion completion, uint32 delayTime);
        void StartAnimation(const std::string &animationName, bool force);
        void Render() override;
        void RenderDebug() override;

    protected:
        void UpdateAnimation();

        Vector2D mOffset;
        std::string mAssetName;
        std::string mDefaultName;
        std::unordered_map<std::string, AnimationPlayInfo> mAnimations;
        AnimationFrame mCurrentAnimation;
    };
}