#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class PhysicsComponent : public Component
    {
    public:
        virtual void PhysicsUpdate(float32 deltaTime) = 0;
    };
}