#pragma once

#include <utils/Vector2D.h>
#include <graphics/IDebugRenderableComponent.h>
#include <physics/components/PhysicsComponent.h>

namespace Gengine
{
    enum class PhysicsBody
    {
        STATIC,
        RIGID
    };

    enum class BodyShape
    {
        CIRCULAR,
        RECTANGULAR
    };

    class CollisionComponent : public PhysicsComponent, IDebugRenderableComponent
    {
    public:
        CollisionComponent();
        CollisionComponent(const float32 mass, const float32 radius, PhysicsBody body, BodyShape shape = BodyShape::CIRCULAR, const Vector2D& offset = Vector2D());
        ~CollisionComponent();

        void Create() override;

        void RenderDebug() override;
        
        void PhysicsUpdate(float32 deltaTime) override;

        const Vector2D& GetCollisionPosition();
        
        float32 mMass;
        float32 mRadius;
        PhysicsBody mPhysicsBody;
        BodyShape mBodyShape;
        Vector2D mOffset;
        
    private:

        void Accelerate(const Vector2D& acceleration);

        Vector2D mOldPosition;
        Vector2D* mCurrentPosition;
        Vector2D mAcceleration;
        
    };
}