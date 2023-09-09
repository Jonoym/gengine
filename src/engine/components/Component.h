#pragma once

#include "../entities/Entity.h"
#include "IComponent.h"

class Component : public IComponent
{

public:
    Component();
    ~Component();

    void update() override;
    void dispose() override;

    bool operator==(const IComponent& other) override;

    void setEntity(Entity &entity);

private:
    Entity *mEntity;
};