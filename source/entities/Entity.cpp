#include <entities/Entity.h>
#include <core/Logger.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    Entity::Entity() {}

    Entity::Entity(const Entity &other)
    {
        this->mPosition = other.mPosition;
        this->mEventHandler = other.mEventHandler;

        this->mComponents = std::move(other.mComponents);
    }

    Entity::~Entity() {}

    void Entity::AddComponent(std::shared_ptr<Component> component, ComponentType type)
    {
        L_INFO("[ENTITY]", "Adding Component");
        component.get()->Attach(this);
        mComponents.push_back(component);

        switch (type)
        {
            case ComponentType::RENDER:
                ServiceManager::GetServiceManager().GetRenderService().Register(component);
        }
    }

    void Entity::SetPosition(const Vector2D &newPosition)
    {
        L_INFO("[ENTITY]", "Setting the Entity Position");

        mPosition = newPosition;
    }

    const Vector2D &Entity::GetPosition()
    {
        L_TRACE("[ENTITY]", "Getting the Entity Position");

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