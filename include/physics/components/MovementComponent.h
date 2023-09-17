#pragma once

#include <physics/components/PhysicsComponent.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    struct DirectionFlags
    {
        bool mLeft = false;
        bool mRight = false;
        bool mUp = false;
        bool mDown = false;
    };

    class MovementComponent : public PhysicsComponent
    {
    public:
        MovementComponent();
        ~MovementComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;
        void PhysicsUpdate(float32 deltaTime) override;
        void UpdateMultipier(const Vector2D& multiplier);

    private:
        void MoveLeftStart();
        void MoveRightStart();
        void MoveUpStart();
        void MoveDownStart();
        void MoveLeftEnd();
        void MoveRightEnd();
        void MoveUpEnd();
        void MoveDownEnd();

        Vector2D mMoveDirection;
        Vector2D mMovementSpeed;

        DirectionFlags mDirections;
    };
}