#include <maps/Map.h>
#include <services/ServiceManager.h>
#include <entities/Entity.h>

#include <core/Logger.h>

namespace Gengine
{
    Map::Map() {}

    Map::~Map() {}

    void Map::Initialise() {
        L_INFO("[MAP]", "Initialising Map Area");

        Entity entity;
        entity.AddComponent(std::make_shared<RenderComponent>("dog", "assets/dog.png", Vector2D(100,100)), ComponentType::RENDER);
        SpawnEntityAt(entity, Vector2D(0, 0));
    }

    void Map::Dispose() {
        L_INFO("[MAP]", "Disposing Map Area");

    }

    void Map::SpawnEntityAt(Entity& entity, const Vector2D &position) {
        L_INFO("[MAP]", "Spawing Entity %f", position.x);

        entity.SetPosition(position);
        ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(entity);
    }

}