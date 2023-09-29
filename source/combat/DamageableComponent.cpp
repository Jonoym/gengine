#include <combat/DamageableComponent.h>
#include <entities/Entity.h>

namespace Gengine
{
    DamageableComponent::DamageableComponent(const float32 radius, BodyShape shape, const Vector2D& offset)
        : CollisionComponent(0.0f, radius, PhysicsBody::TRANSPARENT, shape, offset)
    {

    }

    DamageableComponent::~DamageableComponent()
    {

    }

    void DamageableComponent::HandleCollisionStart(Event* event)
    {
        mEntity->PrepareDisposal();
    }
}