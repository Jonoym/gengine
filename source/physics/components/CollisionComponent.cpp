#include <core/Logger.h>
#include <entities/Entity.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    CollisionComponent::CollisionComponent()
        : mCurrentPosition(nullptr)
        , mMass(1.0f)
        , mRadius(100.0f)
    {}

    CollisionComponent::CollisionComponent(const float32 mass, const float32 radius)
        : mCurrentPosition(nullptr)
        , mMass(mass)
        , mRadius(radius)
    {}

    CollisionComponent::~CollisionComponent() {}

    void CollisionComponent::Create()
    {
        mCurrentPosition = &mEntity->mPosition;
    }

    void CollisionComponent::Update()
    {
    }

    void CollisionComponent::Dispose()
    {
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