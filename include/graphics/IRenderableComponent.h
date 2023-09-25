#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    enum class RenderPriority
    {
        BACKGROUND = 0,
        PARTICLE = 1,
        ENTITY = 2,
        OVERLAY = 3
    };

    class IRenderableComponent : public Component
    {
    public:
        IRenderableComponent(RenderPriority priority, const Vector2D size)
            : mPriority(priority)
            , mSize(size)
        {
        }
        IRenderableComponent(const IRenderableComponent& other) {}
        virtual void Render() = 0;
        RenderPriority GetPriority() { return mPriority; }
        RenderPriority mPriority;
        Vector2D mSize;
    };
}