#pragma once

#include <events/Event.h>
#include <graphics/IDebugRenderableComponent.h>
#include <physics/components/PhysicsComponent.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    enum class PhysicsBody
    {
        STATIC,
        RIGID,
        TRANSPARENT
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

        Vector2D GetCollisionPosition();

        void OnCollisionStart(Event* event);
        void OnCollisionEnd(Event* event);

        virtual void HandleCollisionStart(Event* event) {}
        virtual void HandleCollisionEnd(Event* event) {}

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