#include <core/Logger.h>
#include <entities/Entity.h>
#include <services/ServiceManager.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    CollisionComponent::CollisionComponent() : CollisionComponent(1.0f, 100.0f, PhysicsBody::RIGID)
    {
    }

    CollisionComponent::CollisionComponent(const float32 mass, const float32 radius, PhysicsBody body, BodyShape shape, const Vector2D &offset)
        : IDebugRenderableComponent(DebugColour::RED, BoundType::CIRCULAR), mCurrentPosition(nullptr), mMass(mass), mRadius(radius), mPhysicsBody(body), mBodyShape(shape), mOffset(offset)
    {
        L_INFO("[COLLISION COMPONENT]", "Creating Collision Component");
        ServiceManager::GetServiceManager().GetPhysicsService().RegisterCollider(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterDebug(this);
    }

    CollisionComponent::~CollisionComponent() {}

    void CollisionComponent::Create()
    {
        mCurrentPosition = &mEntity->mPosition;
    }

    void CollisionComponent::PhysicsUpdate(float32 deltaTime)
    {
        const Vector2D velocity = mEntity->mPosition - mOldPosition;

        mOldPosition = *mCurrentPosition;

        *mCurrentPosition = (*mCurrentPosition) + velocity + mAcceleration * deltaTime * deltaTime;

        mAcceleration = {};
    }

    void CollisionComponent::Accelerate(const Vector2D &acceleration)
    {
        mAcceleration += acceleration;
    }

    const Vector2D &CollisionComponent::GetCollisionPosition()
    {
        return mEntity->mPosition;// + mOffset;
    }

    void CollisionComponent::RenderDebug()
    {
        L_TRACE("[COLLISION COMPONENT]", "Rendering Collision Component Debug Bounds");

        ServiceManager::GetServiceManager().GetRenderService().RenderDebug(
            mColour, mBoundType, Box2D(mEntity->mPosition, Vector2D(mRadius * 2, mRadius * 2)));
    }
}