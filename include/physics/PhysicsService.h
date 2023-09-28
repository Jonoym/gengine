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

        void Register(PhysicsComponent *component);
        void RegisterCollider(CollisionComponent *component);

    private:
        void UpdatePositions(float32 deltaTime);
        void SolveCollisions();

        std::vector<PhysicsComponent *> mPhysicsComponents;
        std::vector<CollisionComponent *> mColliderComponents;

        struct PairPointerHash
        {
            std::size_t operator()(const std::pair<CollisionComponent *, CollisionComponent *> &p) const
            {
                std::hash<CollisionComponent *> hash_func;
                return hash_func(p.first) ^ hash_func(p.second);
            }
        };

        struct PairPointerEqual
        {
            bool operator()(
                const std::pair<Gengine::CollisionComponent *, Gengine::CollisionComponent *> &p1,
                const std::pair<Gengine::CollisionComponent *, Gengine::CollisionComponent *> &p2) const
            {
                // Implement your custom equality logic here
                // For example, compare the components pointed to by the pairs
                return (p1.first) == (p2.first) && (p1.second) == (p2.second);
            }
        };

        std::unordered_set<std::pair<CollisionComponent *, CollisionComponent *>, PairPointerHash, PairPointerEqual> mCollided;
        std::unordered_set<std::pair<CollisionComponent *, CollisionComponent *>, PairPointerHash, PairPointerEqual> mPreviousCollided;
    };
}