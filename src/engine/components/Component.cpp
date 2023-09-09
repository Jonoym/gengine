#include "Component.h"

Component::Component()
    : mEntity(nullptr)
{

}

Component::~Component()
{

}

void Component::update()
{

}

void Component::dispose()
{

}

void Component::setEntity(Entity &entity)
{
    mEntity = &entity;
}

bool Component::operator==(const IComponent& other) {
    return false;
}