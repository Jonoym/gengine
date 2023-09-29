#include <core/Logger.h>
#include <entities/Entity.h>
#include <events/EventTypes.h>
#include <services/ServiceManager.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    CollisionComponent::CollisionComponent(const float32 mass, const float32 radius, PhysicsBody body, BodyShape shape, const Vector2D &offset)
        : IDebugRenderableComponent(DebugColour::RED, BoundType::CIRCULAR), mCurrentPosition(nullptr), mMass(mass), mRadius(radius), mPhysicsBody(body), mBodyShape(shape), mOffset(offset)
    {
        L_INFO("[COLLISION COMPONENT]", "Creating Collision Component");
        ServiceManager::GetServiceManager().GetPhysicsService().RegisterCollider(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterDebug(this);
    }

    CollisionComponent::~CollisionComponent() {}

    void CollisionComponent::Create()
    {
        mCurrentPosition = &mEntity->mPosition;

        mEntity->mEventHandler.AddListener("onCollisionStart", [this](Event *event)
                                           { OnCollisionStart(event); });
        mEntity->mEventHandler.AddListener("onCollisionEnd", [this](Event *event)
                                           { OnCollisionEnd(event); });
    }

    void CollisionComponent::Dispose()
    {
        ServiceManager::GetServiceManager().GetPhysicsService().DeregisterCollider(this);
        ServiceManager::GetServiceManager().GetRenderService().DeregisterDebug(this);
    }

    void CollisionComponent::PhysicsUpdate(float32 deltaTime)
    {
        const Vector2D velocity = mEntity->mPosition - mOldPosition;

        mOldPosition = *mCurrentPosition;

        *mCurrentPosition = (*mCurrentPosition) + velocity + mAcceleration * deltaTime * deltaTime;

        mAcceleration = {};
    }

    void CollisionComponent::Accelerate(const Vector2D &acceleration)
    {
        mAcceleration += acceleration;
    }

    Vector2D CollisionComponent::GetCollisionPosition()
    {
        return mEntity->mPosition + mOffset;
    }

    void CollisionComponent::RenderDebug()
    {
        L_TRACE("[COLLISION COMPONENT]", "Rendering Collision Component Debug Bounds");

        ServiceManager::GetServiceManager().GetRenderService().RenderDebug(
            mColour, mBoundType, Box2D(mEntity->mPosition + mOffset, Vector2D(mRadius * 2, mRadius * 2)), RenderPriority::ENTITY);
    }

    void CollisionComponent::OnCollisionStart(Event *event)
    {
        CollisionEvent *collisionEvent = dynamic_cast<CollisionEvent *>(event);
        if (collisionEvent != nullptr)
        {
            L_INFO("[COLLISION COMPONENT]", "Collision Start");
            HandleCollisionStart(collisionEvent);
        }
    }

    void CollisionComponent::OnCollisionEnd(Event *event)
    {
        CollisionEvent *collisionEvent = dynamic_cast<CollisionEvent *>(event);
        if (collisionEvent != nullptr)
        {
            L_INFO("[COLLISION COMPONENT]", "Collision End");
            HandleCollisionEnd(collisionEvent);
        }
    }
}