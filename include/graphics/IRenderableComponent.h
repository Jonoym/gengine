#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    struct IRenderableComponent : public Component
    {
        virtual void Render() = 0;
        virtual const Vector2D& GetSize() = 0;
    };
}