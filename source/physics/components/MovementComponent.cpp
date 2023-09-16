#include <core/Logger.h>
#include <entities/Entity.h>
#include <physics/components/MovementComponent.h>

namespace Gengine
{
    MovementComponent::MovementComponent() {}
    
    MovementComponent::~MovementComponent() {}

    void MovementComponent::Create()
    {
        mEntity->mEventHandler.AddListener("moveLeft", std::bind(&Gengine::MovementComponent::MoveLeft, this));
        mEntity->mEventHandler.AddListener("moveRight", std::bind(&Gengine::MovementComponent::MoveRight, this));
        mEntity->mEventHandler.AddListener("moveUp", std::bind(&Gengine::MovementComponent::MoveUp, this));
        mEntity->mEventHandler.AddListener("moveDown", std::bind(&Gengine::MovementComponent::MoveDown, this));
    }
    void MovementComponent::Update()
    {
    }
    void MovementComponent::Dispose()
    {
    }

    void MovementComponent::MoveLeft()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Left");
        mEntity->mPosition += Vector2D(-10.0f, 0.0f);
    }
    void MovementComponent::MoveRight()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Right");
        mEntity->mPosition += Vector2D(10.0f, 0.0f);
    }
    void MovementComponent::MoveUp()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Up");
        mEntity->mPosition += Vector2D(0.0f, -10.0f);
    }
    void MovementComponent::MoveDown()
    {
        L_INFO("[MOVEMENT COMPONENT]", "Moving Entity Down");
        mEntity->mPosition += Vector2D(0.0f, 10.0f);
    }
}