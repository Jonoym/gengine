#include <maps/Map.h>
#include <services/ServiceManager.h>
#include <entities/Entity.h>

namespace Gengine
{
    Map::Map() {}

    Map::~Map() {}

    void Map::Initialise() {
        Entity entity;
        // entity.AddComponent(std::make_unique<)
        SpawnEntityAt(entity, Vector2D(0, 0));
    }

    void Map::Dispose() {}

    void Map::SpawnEntityAt(Entity& entity, const Vector2D &position) {
        entity.SetPosition(position);

        ServiceManager::getServiceManager().GetEntityService().RegisterEntity(entity);
    }

}