#pragma once

#include <vector>

#include "Entity.h"

class EntityService
{

public:

    EntityService();
    ~EntityService();

    void registerEntity(const Entity &entity);
    void unregisterEntity(const Entity &entity);

    void update();
    void dispose();

private:
    std::vector<Entity> mEntities;
};