#include <core/Logger.h>
#include <entities/Entity.h>
#include <events/EventTypes.h>
#include <physics/PhysicsService.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    PhysicsService::PhysicsService() {}

    PhysicsService::~PhysicsService() {}

    void PhysicsService::Update()
    {
        L_TRACE("[PHYSICS SERVICE]", "Simulating Physics Update");

        float32 deltaTime = ServiceManager::GetServiceManager().GetTimeManager().GetDeltaTime();

        const uint8 subSteps = 8;
        const float32 subDeltaTime = deltaTime / subSteps;

        mCollided.clear();

        for (uint8 i = 0; i < subSteps; i++)
        {
            UpdatePositions(subDeltaTime);
            SolveCollisions();
        }

        L_TRACE("[PHYSICS SERVICE]", "Triggering Collision Start Events");

        // All of the collisions that has happened on this time update
        for (const auto &colliders : mCollided)
        {
            // If it was not part of the previous ones, the collision starts for the first time
            if (!mPreviousCollided.contains(colliders))
            {
                if (!mDeregisteredColliders.contains(colliders.first) && !mDeregisteredColliders.contains(colliders.second))
                {
                    CollisionEvent event{colliders.first, colliders.second};
                    colliders.first->mEntity->mEventHandler.Trigger("onCollisionStart", event);
                    colliders.second->mEntity->mEventHandler.Trigger("onCollisionStart", event);
                }
            }
        }

        L_TRACE("[PHYSICS SERVICE]", "Triggering Collision End Events");
        for (const auto &colliders : mPreviousCollided)
        {
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update1");
            if (!mCollided.contains(colliders))
            {
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update2");
                if (!mDeregisteredColliders.contains(colliders.first) && !mDeregisteredColliders.contains(colliders.second))
                {
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update3");
                    CollisionEvent event{colliders.first, colliders.second};
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update4");
                    colliders.first->mEntity->mEventHandler.Trigger("onCollisionEnd", event);
                    colliders.second->mEntity->mEventHandler.Trigger("onCollisionEnd", event);
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update6");
                }
            }
        }
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update");
        mDeregisteredColliders.clear();
        mPreviousCollided = mCollided;
        L_TRACE("[PHYSICS SERVICE]", "Finishing Physics Update");
    }

    void PhysicsService::Register(PhysicsComponent *component)
    {
        L_TRACE("[PHYSICS SERVICE]", "Registering Physics Component");
        mPhysicsComponents.push_back(component);
    }

    void PhysicsService::RegisterCollider(CollisionComponent *component)
    {
        L_TRACE("[PHYSICS SERVICE]", "Registering Physics Collider Component");
        mColliderComponents.push_back(component);
    }
    void PhysicsService::Deregister(PhysicsComponent *component)
    {
        L_TRACE("[PHYSICS SERVICE]", "Deregistering Physics Component");
        mPhysicsComponents.erase(std::remove(mPhysicsComponents.begin(), mPhysicsComponents.end(), component), mPhysicsComponents.end());
    }

    void PhysicsService::DeregisterCollider(CollisionComponent *component)
    {
        L_TRACE("[PHYSICS SERVICE]", "Deregistering Physics Collider Component");
        mColliderComponents.erase(std::remove(mColliderComponents.begin(), mColliderComponents.end(), component), mColliderComponents.end());
        mDeregisteredColliders.insert(component);
    }

    void PhysicsService::UpdatePositions(float32 deltaTime)
    {
        L_TRACE("[PHYSICS SERVICE]", "Updating Positions of Physics Components");
        for (const auto &component : mPhysicsComponents)
        {
            L_TRACE("[PHYSICS SERVICE]", "Updating Physics Component");
            component->PhysicsUpdate(deltaTime);
        }
    }

    void PhysicsService::SolveCollisions()
    {
        const int32 numColliders = mColliderComponents.size();
        L_TRACE("[PHYSICS SERVICE]", "Solving Collisions between %d Collider Components", numColliders);

        for (uint32 i = 0; i < numColliders; i++)
        {
            auto &collider1 = mColliderComponents.at(i);
            const Vector2D colliderPosition1 = collider1->GetCollisionPosition();

            for (uint32 j = i + 1; j < numColliders; j++)
            {
                auto &collider2 = mColliderComponents.at(j);
                const Vector2D colliderPosition2 = collider2->GetCollisionPosition();

                const Vector2D collisionAxis = colliderPosition1 - colliderPosition2;
                const float32 collisionRadius = collider1->mRadius + collider2->mRadius;

                const float32 distance = collisionAxis.Length();

                if (distance < collisionRadius)
                {
                    L_TRACE("[PHYSICS SERVICE]", "Handling Collision Collider1 Position: { x: %f, y: %f }, Collider2 Position: { x: %f, y: %f }",
                            colliderPosition1.mX, colliderPosition1.mY, colliderPosition2.mX, colliderPosition2.mY);

                    mCollided.insert(std::make_pair(collider1, collider2));

                    if (collider1->mPhysicsBody != PhysicsBody::TRANSPARENT && collider2->mPhysicsBody != PhysicsBody::TRANSPARENT)
                    {
                        const Vector2D strength = collisionAxis / distance;

                        const float32 delta = collisionRadius - distance;
                        if (collider1->mPhysicsBody == PhysicsBody::RIGID)
                            collider1->mEntity->mPosition += strength * delta / collider1->mMass;
                        if (collider2->mPhysicsBody == PhysicsBody::RIGID)
                            collider2->mEntity->mPosition -= strength * delta / collider2->mMass;
                    }
                }
            }
        }
    }
}