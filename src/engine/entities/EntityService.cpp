#include "EntityService.h"

EntityService::EntityService()
{
    Entity::mNextId = 0;
}
EntityService::~EntityService()
{
}

void EntityService::registerEntity(const Entity &entity)
{
}
void EntityService::unregisterEntity(const Entity &entity)
{
}

void EntityService::update()
{
}
void EntityService::dispose()
{
}