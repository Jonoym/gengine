#include "Entity.h"

uint32 Entity::mNextId = 0;

Entity::Entity()
: mId(mNextId++)
{
}

Entity::~Entity()
{
}

uint32 Entity::getId()
{
    return mId;
}

void Entity::setPosition(Vector2D &vector)
{
    mPosition = vector;
}

Vector2D &Entity::getPosition()
{
    return mPosition;
}

void Entity::addComponent(const IComponent &component)
{
    mComponents.push_back(component);
}

void Entity::removeComponent(const IComponent &component)
{
    mComponents.erase(
        std::remove(mComponents.begin(), mComponents.end(), component),
        mComponents.end());
}

void Entity::update()
{
    for (auto component : mComponents)
    {
        component.update();
    }
}

bool Entity::operator==(const Entity &other)
{
    return mId = other.mId;
}