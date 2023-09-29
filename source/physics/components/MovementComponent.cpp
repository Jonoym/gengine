#include <core/Logger.h>
#include <entities/Entity.h>
#include <events/EventTypes.h>
#include <physics/components/MovementComponent.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    MovementComponent::MovementComponent()
        : mMovementSpeed(Vector2D(0.5f, 0.5f)), mMoveDirection(Vector2D())
    {
        ServiceManager::GetServiceManager().GetPhysicsService().Register(this);
    }

    MovementComponent::~MovementComponent() {}

    void MovementComponent::Create()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Creating and Input Component and Adding Listeners");

        mEntity->mEventHandler.AddListener("moveLeftStart", [this](Event *event)
                                           { MoveLeftStart(event); });
        mEntity->mEventHandler.AddListener("moveRightStart", [this](Event *event)
                                           { MoveRightStart(event); });
        mEntity->mEventHandler.AddListener("moveUpStart", [this](Event *event)
                                           { MoveUpStart(event); });
        mEntity->mEventHandler.AddListener("moveDownStart", [this](Event *event)
                                           { MoveDownStart(event); });
        mEntity->mEventHandler.AddListener("moveLeftEnd", [this](Event *event)
                                           { MoveLeftEnd(event); });
        mEntity->mEventHandler.AddListener("moveRightEnd", [this](Event *event)
                                           { MoveRightEnd(event); });
        mEntity->mEventHandler.AddListener("moveUpEnd", [this](Event *event)
                                           { MoveUpEnd(event); });
        mEntity->mEventHandler.AddListener("moveDownEnd", [this](Event *event)
                                           { MoveDownEnd(event); });
    }

    void MovementComponent::PhysicsUpdate(float32 deltaTime)
    {
        if (mMoveDirection != Vector2D::ZERO) {
            mEntity->mPosition += mMoveDirection.Normalise() * mMovementSpeed * deltaTime;
        }
        if (mLastMoveDirection != mMoveDirection)
        {
            TriggerAnimation();
        }
        mLastMoveDirection = mMoveDirection;
    }

    void MovementComponent::UpdateMultipier(const Vector2D &movementSpeed)
    {
        mMovementSpeed = movementSpeed;
    }

    void MovementComponent::MoveLeftStart(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Left");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (!mDirections.mLeft)
            {
                mMoveDirection += Vector2D::LEFT;
                mDirections.mLeft = true;
            }
        }
    }

    void MovementComponent::MoveRightStart(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Right");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (!mDirections.mRight)
            {
                mMoveDirection += Vector2D::RIGHT;
                mDirections.mRight = true;
            }
        }
    }

    void MovementComponent::MoveUpStart(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Up");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (!mDirections.mUp)
            {
                mMoveDirection += Vector2D::UP;
                mDirections.mUp = true;
            }
        }
    }

    void MovementComponent::MoveDownStart(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Down");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (!mDirections.mDown)
            {
                mMoveDirection += Vector2D::DOWN;
                mDirections.mDown = true;
            }
        }
    }

    void MovementComponent::MoveLeftEnd(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Left");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (mDirections.mLeft)
            {
                mMoveDirection -= Vector2D::LEFT;
                mDirections.mLeft = false;
            }
        }
    }
    void MovementComponent::MoveRightEnd(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Right");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (mDirections.mRight)
            {
                mMoveDirection -= Vector2D::RIGHT;
                mDirections.mRight = false;
            }
        }
    }
    void MovementComponent::MoveUpEnd(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Up");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (mDirections.mUp)
            {
                mMoveDirection -= Vector2D::UP;
                mDirections.mUp = false;
            }
        }
    }
    void MovementComponent::MoveDownEnd(Event *event)
    {
        L_TRACE("[MOVEMENT COMPONENT]", "Moving Entity Down");
        MovementEvent *movementEvent = dynamic_cast<MovementEvent *>(event);
        if (movementEvent != nullptr)
        {
            if (mDirections.mDown)
            {
                mMoveDirection -= Vector2D::DOWN;
                mDirections.mDown = false;
            }
        }
    }

    void MovementComponent::TriggerAnimation()
    {
        AnimateEvent event;
        if (mMoveDirection.mX != 0 || mMoveDirection.mY != 0)
            AnimateMoveDirection(mLastMoveDirection);
        else
            AnimateEndDirection(mLastMoveDirection);
    }

    void MovementComponent::AnimateMoveDirection(const Vector2D direction)
    {
        AnimateEvent event;
        if (mMoveDirection.mY != 0)
        {
            if (mMoveDirection.mY > 0)
                mEntity->mEventHandler.Trigger("animateDownStart", event);
            else
                mEntity->mEventHandler.Trigger("animateUpStart", event);
        }
        else
        {
            if (mMoveDirection.mX > 0)
                mEntity->mEventHandler.Trigger("animateRightStart", event);
            else
                mEntity->mEventHandler.Trigger("animateLeftStart", event);
        }
    }

    void MovementComponent::AnimateEndDirection(const Vector2D direction)
    {
        AnimateEvent event;
        if (mLastMoveDirection.mY != 0)
        {
            if (mLastMoveDirection.mY > 0)
                mEntity->mEventHandler.Trigger("animateDownEnd", event);
            else
                mEntity->mEventHandler.Trigger("animateUpEnd", event);
        }
        else
        {
            if (mLastMoveDirection.mX > 0)
                mEntity->mEventHandler.Trigger("animateRightEnd", event);
            else
                mEntity->mEventHandler.Trigger("animateLeftEnd", event);
        }
    }
}