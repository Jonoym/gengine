#pragma once

#include <components/Component.h>
#include <graphics/AnimateComponent.h>

namespace Gengine
{
    class AnimationController : public Component
    {
    public:
        AnimationController(const std::string& assetName, const std::string& path, const Vector2D& size);
        virtual ~AnimationController();

        virtual void Create() override;
        virtual void Dispose() override;
    protected:
        AnimateComponent mAnimateComponent;
    };
}