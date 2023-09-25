#include <core/Logger.h>
#include <entities/Entity.h>
#include <services/ServiceManager.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    CollisionComponent::CollisionComponent() : CollisionComponent(1.0f, 100.0f, PhysicsBody::RIGID) {}

    CollisionComponent::CollisionComponent(const float32 mass, const float32 radius, PhysicsBody body)
        : mCurrentPosition(nullptr)
        , mMass(mass)
        , mRadius(radius)
        , mPhysicsBody(body)
    {
        ServiceManager::GetServiceManager().GetPhysicsService().RegisterCollider(this);
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

    void CollisionComponent::Accelerate(const Vector2D& acceleration)
    {
        mAcceleration += acceleration;
    }
}