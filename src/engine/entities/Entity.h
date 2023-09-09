#pragma once

#include <stdlib.h>
#include <vector>

#include "../components/IComponent.h"
#include "../math/Vector2D.h"
#include "../Types.h"

class Entity {

public:
    static u_int32_t mNextId;

    Entity();
    ~Entity();

    uint32 getId();

    void setPosition(Vector2D& vector);
    Vector2D& getPosition();

    void addComponent(const IComponent& component);
    void removeComponent(const IComponent& component);

    void update();

    bool operator== (const Entity& other);

private:
    uint32 mId;
    
    Vector2D mPosition;
    std::vector<IComponent> mComponents;

};