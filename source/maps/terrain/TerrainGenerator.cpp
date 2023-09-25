#include <maps/terrain/TerrainGenerator.h>
#include <entities/Entity.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>
#include <physics/components/MovementComponent.h>
#include <graphics/AnimationComponent.h>

namespace Gengine
{
    TerrainGenerator::TerrainGenerator()
    {
    }

    TerrainGenerator::~TerrainGenerator()
    {
    }

    void TerrainGenerator::GenerateTerrain(const std::string &map)
    {
        L_INFO("[TERRAIN GENERATOR]", "Generating Terrain");

        for (auto row = 0; row < ROW_LENGTH; row++)
        {
            for (auto col = 0; col < COLUMN_HEIGHT; col++)
            {
                std::string tileType = row % 3 == 0 ? "grass" : row % 3 == 1 ? "stone"
                                                                             : "flower";
                std::unique_ptr<Entity> terrainEntity = std::make_unique<Entity>();
                std::shared_ptr<AnimationComponent> tile =
                    std::make_shared<AnimationComponent>("terrain", "assets/terrainSprites.png", "assets/terrain.atlas",
                                                         Vector2D(TILE_SIZE, TILE_SIZE), RenderPriority::BACKGROUND, Vector2D(TILE_SIZE * row, TILE_SIZE * col), tileType);
                terrainEntity->AddComponent(tile);

                ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(terrainEntity));
            }
        }

        {
            std::unique_ptr<Entity> terrainEntity2 = std::make_unique<Entity>();
            std::shared_ptr<AnimationComponent> tile2 =
                std::make_shared<AnimationComponent>("terrainObject", "assets/terrainObjectSprites.png", "assets/terrainObject.atlas",
                                                     Vector2D(100.0f, 100.0f), RenderPriority::ENTITY, Vector2D(), "rock");

            terrainEntity2->AddComponent(tile2);
            terrainEntity2->AddComponent(std::make_shared<CollisionComponent>(100.0f, 50.0f, PhysicsBody::STATIC));

            terrainEntity2->mPosition = Vector2D(1000.0f, 500.0f);
            ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(terrainEntity2));
        }
        {
            std::unique_ptr<Entity> terrainEntity3 = std::make_unique<Entity>();
            std::shared_ptr<AnimationComponent> tile3 =
                std::make_shared<AnimationComponent>("terrainObject", "assets/terrainObjectSprites.png", "assets/terrainObject.atlas",
                                                     Vector2D(300.0f, 400.0f), RenderPriority::ENTITY, Vector2D(), "tree");

            terrainEntity3->AddComponent(tile3);
            terrainEntity3->AddComponent(std::make_shared<CollisionComponent>(100.0f, 50.0f, PhysicsBody::STATIC));

            terrainEntity3->mPosition = Vector2D(1200.0f, 800.0f);
            ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(terrainEntity3));
        }
        // {
        //     std::unique_ptr<Entity> terrainEntity3 = std::make_unique<Entity>();
        //     std::shared_ptr<AnimationComponent> tile3 =
        //         std::make_shared<AnimationComponent>("terrainObject", "assets/terrainObjectSprites.png", "assets/terrainObject.atlas",
        //                                              Vector2D(400.0f, 300.0f), RenderPriority::ENTITY, Vector2D(), "tree");

        //     terrainEntity3->AddComponent(tile3);
        //     terrainEntity3->AddComponent(std::make_shared<CollisionComponent>(100.0f, 50.0f));

        //     terrainEntity3->mPosition = Vector2D(1000.0f, 500.0f);
        //     ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(terrainEntity3));
        // }
        // {
        //     std::unique_ptr<Entity> terrainEntity2 = std::make_unique<Entity>();
        //     std::shared_ptr<AnimationComponent> tile2 =
        //         std::make_shared<AnimationComponent>("terrainObject", "assets/terrainObjectSprites.png", "assets/terrainObject.atlas",
        //                                              Vector2D(100.0f, 100.0f), RenderPriority::ENTITY, Vector2D(), "sign");

        //     terrainEntity2->AddComponent(tile2);
        //     terrainEntity2->AddComponent(std::make_shared<CollisionComponent>(100.0f, 50.0f));

        //     terrainEntity2->mPosition = Vector2D(1000.0f, 500.0f);
        //     ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(terrainEntity2));
        // }
    }
}
