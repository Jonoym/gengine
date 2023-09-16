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
        void Update(float32 deltaTime);
        void UpdatePositions(float32 deltaTime);
        void SolveCollisions();
        void Dispose() override;

        void Register(const std::shared_ptr<Component> component);
        void RegisterCollider(const std::shared_ptr<Component> component);

    private:
        std::vector<std::shared_ptr<PhysicsComponent>> mPhysicsComponents;
        std::vector<std::shared_ptr<CollisionComponent>> mColliderComponents;
    };
}