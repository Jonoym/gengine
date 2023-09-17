#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class PhysicsComponent : public Component
    {
    public:
        virtual void Create() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

        virtual void PhysicsUpdate(float32 deltaTime) = 0;
    };
}