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

        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->AddComponent(std::make_shared<RenderComponent>("dog", "assets/dog.png", Vector2D(100.0f, 100.0f)), ComponentType::RENDER);
        SpawnEntityAt(std::move(entity), Vector2D(200.0f, 200.0f));

        for (float i = 0; i < 600; i += 100)
        {
            std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
            entity2->AddComponent(std::make_shared<RenderComponent>("snake", "assets/snake.png", Vector2D(100.0f, 100.0f)), ComponentType::RENDER);
            entity2->AddComponent(std::make_shared<InputComponent>(), ComponentType::INPUT);
            SpawnEntityAt(std::move(entity2), Vector2D(i, i));
        }

    }

    void Map::Dispose() {
        L_INFO("[MAP]", "Disposing Map Area");

    }

    void Map::SpawnEntityAt(std::unique_ptr<Entity> entity, const Vector2D &position) {
        L_INFO("[ENTITY]", "Spawning the Entity at Position: { x: %f, y: %f }", entity->mPosition.x, entity->mPosition.y);

        entity->SetPosition(position);
        ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(entity));
    }

}