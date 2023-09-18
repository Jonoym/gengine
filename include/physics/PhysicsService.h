#pragma once

#include <Includes.h>
#include <services/IService.h>
#include <utils/Box2D.h>
#include <physics/components/PhysicsComponent.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    class PhysicsService : public IService
    {
    public:
        PhysicsService();
        ~PhysicsService();

        void Update() override;

        void Register(PhysicsComponent* component);
        void RegisterCollider(CollisionComponent* component);

    private:
        void UpdatePositions(float32 deltaTime);
        void SolveCollisions();

        std::vector<PhysicsComponent*> mPhysicsComponents;
        std::vector<CollisionComponent*> mColliderComponents;
    };
}