#include <core/Logger.h>
#include <combat/ProjectileSpawnerComponent.h>
#include <events/EventTypes.h>
#include <services/ServiceManager.h>
namespace Gengine
{
    ProjectileSpawnerComponent::ProjectileSpawnerComponent(float32 range, const std::string &assetName,
                                                           const std::string &texturePath,
                                                           const std::string &atlasPath,
                                                           const Vector2D &size)
        : mActive(false), mMouseLocation(Vector2D()), mLastProjectile(0), mRange(range), mAssetName(assetName), mTexturePath(texturePath), mAtlasPath(atlasPath), mSize(size)
    {
    }

    ProjectileSpawnerComponent::~ProjectileSpawnerComponent() {}

    void ProjectileSpawnerComponent::Create()
    {
        mEntity->mEventHandler.AddListener("onClick", [this](Event *event)
                                           {
            MouseEvent *mouseEvent = dynamic_cast<MouseEvent *>(event);
            if (mouseEvent != nullptr) {
                L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Handling Mouse Button Pressed");
                mActive = true;
                mMouseLocation = Vector2D(mouseEvent->mX, mouseEvent->mY);
            } });
        mEntity->mEventHandler.AddListener("onRelease", [this](Event *event)
                                           {
            MouseEvent *mouseEvent = dynamic_cast<MouseEvent *>(event);
            if (mouseEvent != nullptr)
            {
                L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Handling Mouse Button Released");
                mActive = false;
            } });
        mEntity->mEventHandler.AddListener("onMove", [this](Event *event)
                                           {
            MouseEvent *mouseEvent = dynamic_cast<MouseEvent *>(event);
            if (mouseEvent != nullptr) {
                L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Handling Mouse Move");
                mMouseLocation = Vector2D(mouseEvent->mX, mouseEvent->mY);
            } });
    }

    void ProjectileSpawnerComponent::Update()
    {
        L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Updating Projectile Spawner Component");
        uint32 currentTime = ServiceManager::GetServiceManager().GetTimeManager().GetTicks();

        if (mActive && currentTime > mLastProjectile + 100)
        {
            L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Attempting to Spawn Projectile");
            mLastProjectile = currentTime;
            SpawnProjectile();
        }
    }

    void ProjectileSpawnerComponent::SpawnProjectile()
    {
        L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Spawning Projectile at Position: { x: %f, y: %f }", mEntity->mPosition.mX, mEntity->mPosition.mY);

        const Box2D& screenProperties =  ServiceManager::GetServiceManager().GetRenderService().GetCamera()->GetWindowPosition();
        Vector2D direction = (mMouseLocation - Vector2D(screenProperties.mW / 2, screenProperties.mH / 2)).Normalise();

        L_TRACE("[PROJECTILE SPAWNER COMPONENT]", "Spawning Projectile with Direction: { x: %f, y: %f }", direction.mX, direction.mY);

        std::unique_ptr<Entity> projectileEntity = ProjectileFactory::CreateProjectile(mEntity->mPosition, direction, mRange, mAssetName, mTexturePath, mAtlasPath, mSize);

        ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(projectileEntity));
    }
}