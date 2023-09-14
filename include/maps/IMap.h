#pragma once

#include <Includes.h>
#include <entities/Entity.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    struct IMap
    {
        virtual void Initialise() = 0;
        virtual void Dispose() = 0;
        virtual void SpawnEntityAt(Entity& entity, const Vector2D &position) = 0;
    };
}