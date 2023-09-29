#include <entities/Entity.h>
#include <core/Logger.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    Entity::Entity()
        : mPosition(Vector2D(0.0f, 0.0f))
        , mDispose(false)
        {}

    Entity::Entity(const Entity &other)
        : mPosition(Vector2D(other.mPosition.mX, other.mPosition.mY))
        , mDispose(false)
    {
        this->mEventHandler = other.mEventHandler;

        this->mComponents = std::move(other.mComponents);
    }

    Entity::~Entity() {}

    void Entity::AddComponent(std::shared_ptr<Component> component)
    {
        L_INFO("[ENTITY]", "Adding Component");
        component->Attach(this);
        component->Create();
        mComponents.push_back(std::move(component));
    }

    void Entity::SetPosition(Vector2D newPosition)
    {
        L_INFO("[ENTITY]", "Setting the Entity Position: { %f, %f }", newPosition.mX, newPosition.mY);

        mPosition = newPosition;
    }

    const Vector2D &Entity::GetPosition()
    {
        L_TRACE("[ENTITY]", "Getting the Entity Position: { %f, %f }", mPosition.mX, mPosition.mY);

        return mPosition;
    }

    void Entity::Update()
    {
        L_TRACE("[ENTITY]", "Updating Entity Components");
        for (auto& component : mComponents)
        {
            component->Update();
        }
    }

    void Entity::PrepareDisposal()
    {
        L_TRACE("[ENTITY]", "Preparing Entity for Disposal");
        mDispose = true;
    }

    bool Entity::ShouldDispose()
    {
        L_TRACE("[ENTITY]", "Preparing Entity for Disposal");
        return mDispose;
    }

    void Entity::Dispose()
    {
        L_TRACE("[ENTITY]", "Disposing Entity Components");
        for (auto& component : mComponents)
        {
            component->Dispose();
        }
        mComponents.clear();
    }
}