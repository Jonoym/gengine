#include <core/Logger.h>
#include <entities/Entity.h>
#include <physics/components/MovementComponent.h>

namespace Gengine
{
    MovementComponent::MovementComponent()
        : mMovementSpeed(Vector2D(1.0f, 1.0f)), mMoveDirection(Vector2D()) {}

    MovementComponent::~MovementComponent() {}

    void MovementComponent::Create()
    {
        mEntity->mEventHandler.AddListener("moveLeftStart", std::bind(&Gengine::MovementComponent::MoveLeftStart, this));
        mEntity->mEventHandler.AddListener("moveRightStart", std::bind(&Gengine::MovementComponent::MoveRightStart, this));
        mEntity->mEventHandler.AddListener("moveUpStart", std::bind(&Gengine::MovementComponent::MoveUpStart, this));
        mEntity->mEventHandler.AddListener("moveDownStart", std::bind(&Gengine::MovementComponent::MoveDownStart, this));
        mEntity->mEventHandler.AddListener("moveLeftEnd", std::bind(&Gengine::MovementComponent::MoveLeftEnd, this));
        mEntity->mEventHandler.AddListener("moveRightEnd", std::bind(&Gengine::MovementComponent::MoveRightEnd, this));
        mEntity->mEventHandler.AddListener("moveUpEnd", std::bind(&Gengine::MovementComponent::MoveUpEnd, this));
        mEntity->mEventHandler.AddListener("moveDownEnd", std::bind(&Gengine::MovementComponent::MoveDownEnd, this));
    }
    void MovementComponent::Update()
    {
    }

    void MovementComponent::Dispose()
    {
    }

    void MovementComponent::PhysicsUpdate(float32 deltaTime)
    {
        Vector2D multiplier = (mDirections.mLeft || mDirections.mRight) && (mDirections.mUp || mDirections.mDown) ? Vector2D(0.707f, 0.707f) : Vector2D(1.0f, 1.0f); 

        mEntity->mPosition += mMoveDirection * mMovementSpeed * multiplier * deltaTime;
    }

    void MovementComponent::UpdateMultipier(const Vector2D &movementSpeed)
    {
        mMovementSpeed = movementSpeed;
    }

    void MovementComponent::MoveLeftStart()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Left");
        if (!mDirections.mLeft)
        {
            mMoveDirection += Vector2D::LEFT;
            mDirections.mLeft = true;
        }
    }

    void MovementComponent::MoveRightStart()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Right");
        if (!mDirections.mRight)
        {
            mMoveDirection += Vector2D::RIGHT;
            mDirections.mRight = true;
        }
    }

    void MovementComponent::MoveUpStart()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Up");
        if (!mDirections.mUp)
        {
            mMoveDirection += Vector2D::UP;
            mDirections.mUp = true;
        }
    }

    void MovementComponent::MoveDownStart()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Down");
        if (!mDirections.mDown)
        {
            mMoveDirection += Vector2D::DOWN;
            mDirections.mDown = true;
        }
    }

    void MovementComponent::MoveLeftEnd()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Left");
        if (mDirections.mLeft)
        {
            mMoveDirection -= Vector2D::LEFT;
            mDirections.mLeft = false;
        }
    }
    void MovementComponent::MoveRightEnd()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Right");
        if (mDirections.mRight)
        {
            mMoveDirection -= Vector2D::RIGHT;
            mDirections.mRight = false;
        }
    }
    void MovementComponent::MoveUpEnd()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Up");
        if (mDirections.mUp)
        {
            mMoveDirection -= Vector2D::UP;
            mDirections.mUp = false;
        }
    }
    void MovementComponent::MoveDownEnd()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Down");
        if (mDirections.mDown)
        {
            mMoveDirection -= Vector2D::DOWN;
            mDirections.mDown = false;
        }
    }
}