#pragma once

#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    class DamageableComponent : public CollisionComponent
    {
    public:
        DamageableComponent(const float32 radius, BodyShape shape = BodyShape::CIRCULAR, const Vector2D& offset = Vector2D());
        ~DamageableComponent();

        void HandleCollisionStart(Event* event) override;
    };
}