#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>
#include <services/ServiceManager.h>
#include <combat/ProjectileFactory.h>

namespace Gengine
{
    class ProjectileSpawnerComponent : public Component
    {
    public:
        ProjectileSpawnerComponent(float32 range, const std::string &assetName,
                                   const std::string &texturePath,
                                   const std::string &atlasPath,
                                   const Vector2D &size);
        ~ProjectileSpawnerComponent();

        void Create() override;
        void Update() override;
        void SpawnProjectile();

    private:
        bool mActive;
        Vector2D mMouseLocation;

        uint32 mLastProjectile;

        uint32 mDelay;
        float32 mRange;
        std::string mAssetName;
        std::string mTexturePath;
        std::string mAtlasPath;
        Vector2D mSize;
    };
}