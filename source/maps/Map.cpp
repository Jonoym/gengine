#include <maps/Map.h>
#include <services/ServiceManager.h>
#include <entities/Entity.h>
#include <input/InputMovementComponent.h>
#include <physics/components/MovementComponent.h>

#include <core/Logger.h>

namespace Gengine
{
    Map::Map() {}

    Map::~Map() {}

    void Map::Initialise() {
        L_INFO("[MAP]", "Initialising Map Area");

        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->AddComponent(std::make_shared<RenderComponent>("dog", "assets/dog.png", Vector2D(400.0f, 400.0f)), ComponentType::RENDER);
        entity->AddComponent(std::make_shared<InputMovementComponent>(), ComponentType::INPUT);
        entity->AddComponent(std::make_shared<MovementComponent>(), ComponentType::OTHER);
        SpawnEntityAt(std::move(entity), Vector2D(0.0f, 0.0f));

        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        entity2->AddComponent(std::make_shared<RenderComponent>("snake", "assets/snake.png", Vector2D(200.0f, 200.0f)), ComponentType::RENDER);
        entity2->AddComponent(std::make_shared<InputMovementComponent>(), ComponentType::INPUT);
        entity2->AddComponent(std::make_shared<MovementComponent>(), ComponentType::OTHER);
        SpawnEntityAt(std::move(entity2), Vector2D(200.0f, 200.0f));
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