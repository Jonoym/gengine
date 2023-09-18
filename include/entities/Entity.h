#pragma once

#include <Includes.h>
#include <events/EventHandler.h>
#include <utils/Vector2D.h>
#include <components/Component.h>

namespace Gengine
{
    class Component;

    class Entity
    {

    public:
        Entity();
        Entity(const Entity& other);
        ~Entity();

        void AddComponent(std::shared_ptr<Component> component);
        void SetPosition(Vector2D newPosition);
        const Vector2D &GetPosition();

        void Update();
        void Dispose();

        Vector2D mPosition;
        EventHandler mEventHandler;
        std::vector<std::shared_ptr<Component>> mComponents;
    };
}