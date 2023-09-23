#pragma once

namespace Gengine
{
    class Event
    {
    protected:
        virtual ~Event() {}
    };

    class MovementEvent : public Event
    {
    };

    class AnimateEvent : public Event
    {
    };

    class CollisionEvent : public Event
    {
    };
}