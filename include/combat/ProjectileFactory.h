#pragma once

#include <entities/Entity.h>
#include <graphics/AnimationComponent.h>
#include <combat/ProjectileMovementComponent.h>
#include <physics/components/CollisionComponent.h>

namespace Gengine
{
    class ProjectileFactory
    {
    public:
        static std::unique_ptr<Entity> CreateProjectile(const Vector2D &startPosition, const Vector2D &direction, float32 range, const std::string &assetName,
                                                        const std::string &texturePath,
                                                        const std::string &atlasPath,
                                                        const Vector2D &size);
    };
}