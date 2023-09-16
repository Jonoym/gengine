#include <entities/Entity.h>
#include <core/Logger.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    Entity::Entity()
        : mPosition(Vector2D(0.0f, 0.0f)) {}

    Entity::Entity(const Entity &other)
        : mPosition(Vector2D(other.mPosition.x, other.mPosition.y))
    {
        this->mEventHandler = other.mEventHandler;

        this->mComponents = std::move(other.mComponents);
    }

    Entity::~Entity() {}

    void Entity::AddComponent(std::shared_ptr<Component> component, ComponentType type)
    {
        L_INFO("[ENTITY]", "Adding Component");
        component->Attach(this);
        component->Create();
        mComponents.push_back(component);

        switch (type)
        {
            case ComponentType::RENDER:
                ServiceManager::GetServiceManager().GetRenderService().Register(component);
                break;
            case ComponentType::INPUT:
                ServiceManager::GetServiceManager().GetInputHandler().Register(component);
                break;
        }
    }

    void Entity::SetPosition(Vector2D newPosition)
    {
        L_INFO("[ENTITY]", "Setting the Entity Position: { %f, %f }", newPosition.x, newPosition.y);

        mPosition = newPosition;
    }

    const Vector2D &Entity::GetPosition()
    {
        L_TRACE("[ENTITY]", "Getting the Entity Position: { %f, %f }", mPosition.x, mPosition.y);

        return mPosition;
    }

    void Entity::Dispose()
    {
        L_INFO("[ENTITY]", "Disposing Entity Components");
        for (auto& component : mComponents)
        {
            component->Dispose();
        }
    }
}