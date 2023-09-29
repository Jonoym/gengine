#pragma once

#include <physics/components/PhysicsComponent.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class ProjectileMovementComponent : public PhysicsComponent
    {
        public:

            ProjectileMovementComponent(const Vector2D startPosition, const Vector2D direction, float32 range);
            ~ProjectileMovementComponent();

            void Create() override;
            void PhysicsUpdate(float32 deltaTime) override;

        private:
            Vector2D mStartPosition;
            Vector2D mDirection;
            float32 mRange;
    };
}