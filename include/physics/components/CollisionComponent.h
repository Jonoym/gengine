#pragma once

#include <utils/Vector2D.h>
#include <physics/components/PhysicsComponent.h>

namespace Gengine
{
    enum class PhysicsBody
    {
        STATIC,
        RIGID
    };

    class CollisionComponent : public PhysicsComponent
    {
    public:
        CollisionComponent();
        CollisionComponent(const float32 mass, const float32 radius, PhysicsBody body);
        ~CollisionComponent();

        void Create() override;
        
        void PhysicsUpdate(float32 deltaTime) override;
        float32 mMass;
        float32 mRadius;
        PhysicsBody mPhysicsBody;
        
    private:

        void Accelerate(const Vector2D& acceleration);

        Vector2D mOldPosition;
        Vector2D* mCurrentPosition;
        Vector2D mAcceleration;
        
    };
}