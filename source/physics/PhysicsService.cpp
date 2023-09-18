#include <core/Logger.h>
#include <entities/Entity.h>
#include <physics/PhysicsService.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    PhysicsService::PhysicsService() {}

    PhysicsService::~PhysicsService() {}

    void PhysicsService::Update() {
        L_TRACE("[PHYSICS SERVICE]", "Simulating Physics Update");

        float32 deltaTime = ServiceManager::GetServiceManager().GetTimeManager().GetDeltaTime();

        const uint8 subSteps = 8;
        const float32 subDeltaTime = deltaTime / subSteps;

        for (uint8 i = 0; i < subSteps; i++) {
            UpdatePositions(subDeltaTime);
            SolveCollisions();
        }
    }

    void PhysicsService::Register(PhysicsComponent* component)
    {
        L_INFO("[PHYSICS SERVICE]", "Registering Physics Component");
        mPhysicsComponents.push_back(component);
    }

    void PhysicsService::RegisterCollider(CollisionComponent* component)
    {
        L_INFO("[PHYSICS SERVICE]", "Registering Physics Collider Component");
        mColliderComponents.push_back(component);
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
            const Vector2D colliderPosition1 = collider1->mEntity->mPosition;

            for (uint32 j = i + 1; j < numColliders; j++)
            {
                auto &collider2 = mColliderComponents.at(j);
                const Vector2D colliderPosition2 = collider2->mEntity->mPosition;
                
                const Vector2D collisionAxis = colliderPosition1 - colliderPosition2;
                const float32 collisionRadius = collider1->mRadius + collider2->mRadius;

                const float32 distance = collisionAxis.Length();

                if (distance < collisionRadius)
                {
                    L_TRACE("[PHYSICS SERVICE]", "Handling Collision Collider1 Position: { x: %f, y: %f }, Collider2 Position: { x: %f, y: %f }",
                        colliderPosition1.mX, colliderPosition1.mY, colliderPosition2.mX, colliderPosition2.mY);
                        
                    const Vector2D strength = collisionAxis / distance;

                    const float32 delta = collisionRadius - distance;
                    collider1->mEntity->mPosition += strength * 0.5f * delta / collider1->mMass;
                    collider2->mEntity->mPosition -= strength * 0.5f * delta / collider2->mMass;
                }
            }
        }
    }
}