#include <entities/Entity.h>

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

    void Entity::AddComponent(std::shared_ptr<Component> component)
    {
        mComponents.push_back(std::move(component));
    }

    void Entity::SetPosition(const Vector2D &newPosition)
    {
    }
    const Vector2D &Entity::GetPosition()
    {
        return mPosition;
    }
}