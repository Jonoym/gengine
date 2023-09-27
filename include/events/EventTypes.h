#pragma once

#include <events/Event.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{

    class MovementEvent : public Event
    {
    };

    class AnimateEvent : public Event
    {
    };

    class CollisionEvent : public Event
    {
    public:
        CollisionEvent(CollisionComponent *c1, CollisionComponent *c2)
            : mCollider(c1), mOtherCollider(c2) {}

        CollisionComponent *mCollider;
        CollisionComponent *mOtherCollider;
    };
}