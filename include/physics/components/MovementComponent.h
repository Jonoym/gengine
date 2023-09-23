#pragma once

#include <physics/components/PhysicsComponent.h>
#include <utils/Vector2D.h>
#include <events/Event.h>

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
        void PhysicsUpdate(float32 deltaTime) override;
        void UpdateMultipier(const Vector2D& multiplier);

    private:
        void MoveLeftStart(Event* event);
        void MoveRightStart(Event* event);
        void MoveUpStart(Event* event);
        void MoveDownStart(Event* event);
        void MoveLeftEnd(Event* event);
        void MoveRightEnd(Event* event);
        void MoveUpEnd(Event* event);
        void MoveDownEnd(Event* event);

        void TriggerAnimation();
        void AnimateMoveDirection(const Vector2D direction);
        void AnimateEndDirection(const Vector2D direction);

        Vector2D mLastMoveDirection;
        Vector2D mMoveDirection;
        Vector2D mMovementSpeed;

        DirectionFlags mDirections;
    };
}