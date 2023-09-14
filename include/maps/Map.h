#pragma once

#include <maps/IMap.h>

namespace Gengine
{
    class Map : public IMap
    {
    public:
        Map();
        ~Map();

        void Initialise() override;
        void Dispose() override;
        void SpawnEntityAt(Entity& entity, const Vector2D &position) override;
    };
}