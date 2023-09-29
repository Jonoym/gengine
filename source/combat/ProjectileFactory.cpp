#include <core/Logger.h>
#include <combat/ProjectileFactory.h>
#include <combat/ProjectileMovementComponent.h>

namespace Gengine
{
    std::unique_ptr<Entity> ProjectileFactory::CreateProjectile(const Vector2D &startPosition, const Vector2D &direction, float32 range, const std::string &assetName,
                                                                const std::string &texturePath,
                                                                const std::string &atlasPath,
                                                                const Vector2D &size)
    {
        L_INFO("[PROJECTILE FACTORY]", "Creating Projectile at Position: { x: %f, y: %f }, with Asset: '%s'", startPosition.mX, startPosition.mY, assetName.c_str());

        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

        entity->AddComponent(std::make_shared<ProjectileMovementComponent>(startPosition, direction, 100.0f));
        entity->AddComponent(std::make_shared<AnimationComponent>("terrainObject", "assets/terrainObjectSprites.png", "assets/terrainObject.atlas",
                                                                  Vector2D(100.0f, 100.0f), RenderPriority::ENTITY, Vector2D(), "rock"));
        entity->AddComponent(std::make_shared<CollisionComponent>(1.0f, 20.0f, PhysicsBody::TRANSPARENT));
        // entity->AddComponent(std::make_shared<ProjectileMovementComponent>(startPosition, direction, range));
        // entity->AddComponent(std::make_shared<AnimationComponent>(assetName, texturePath, atlasPath, size, RenderPriority::ENTITY));
        // entity->AddComponent(std::make_shared<CollisionComponent>(1.0f, 20.0f, PhysicsBody::TRANSPARENT));

        return std::move(entity);
    }
}