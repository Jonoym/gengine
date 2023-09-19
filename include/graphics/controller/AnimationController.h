#pragma once

#include <components/Component.h>
#include <graphics/AnimateComponent.h>

namespace Gengine
{
    class AnimationController : public Component
    {
    public:
        AnimationController(const std::string& assetName, const std::string& texturePath, const std::string& atlasPath, const Vector2D& size);
        virtual ~AnimationController();
        virtual void Create() override;
        virtual void Dispose() override;

        virtual void AddAnimation(const std::string& animationName, uint32 delayTime);
    protected:
        AnimateComponent mAnimateComponent;
    };
}