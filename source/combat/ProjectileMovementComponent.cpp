#include <core/Logger.h>
#include <combat/ProjectileMovementComponent.h>
#include <entities/Entity.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    ProjectileMovementComponent::ProjectileMovementComponent(const Vector2D startPosition, const Vector2D direction, float32 range)
        : mStartPosition(startPosition), mDirection(direction), mRange(range)
    {
        ServiceManager::GetServiceManager().GetPhysicsService().Register(this);
    }

    ProjectileMovementComponent::~ProjectileMovementComponent()
    {
    }

    void ProjectileMovementComponent::Create()
    {
        mEntity->mPosition = mStartPosition;
    }

    void ProjectileMovementComponent::Dispose()
    {
        ServiceManager::GetServiceManager().GetPhysicsService().Deregister(this);
    }

    void ProjectileMovementComponent::PhysicsUpdate(float32 deltaTime)
    {
        L_TRACE("[PROJECTILE MOVEMENT COMPONENT]", "Updating Position of Projectile by Direction: { x: %f, y: %f}", mDirection.mX, mDirection.mY);
        mEntity->mPosition += mDirection * deltaTime;

        Vector2D distanceTravelled = mEntity->mPosition - mStartPosition;

        if (distanceTravelled.Length() > mRange)
        {
            mEntity->PrepareDisposal();
        }
    }
}