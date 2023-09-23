#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    enum class RenderPriority
    {
        BACKGROUND = 0,
        ENTITY = 1,
        OVERLAY = 2
    };

    class IRenderableComponent : public Component
    {
    public:
        IRenderableComponent(RenderPriority priority)
            : mPriority(priority)
        {
        }
        IRenderableComponent(const IRenderableComponent& other) {}
        virtual void Render() = 0;
        virtual const Vector2D &GetSize() = 0;
        RenderPriority GetPriority() { return mPriority; }
        RenderPriority mPriority;
    };
}