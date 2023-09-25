#pragma once

#include <events/Event.h>
#include <components/Component.h>
#include <graphics/AnimationComponent.h>

namespace Gengine
{
    class AnimationController : public Component
    {
    public:
        AnimationController(const std::string &assetName,
                            const std::string &texturePath,
                            const std::string &atlasPath,
                            const Vector2D &size,
                            RenderPriority priority);
        virtual ~AnimationController();
        virtual void Create() override;
        virtual void Dispose() override;

        virtual void AddAnimation(const std::string &animationName, AnimationPlaythrough playthrough,
                                  AnimationCompletion completion, uint32 delayTime);

    protected:
        AnimationComponent mAnimationComponent;
    };
}