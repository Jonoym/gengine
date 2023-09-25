#include <graphics/RenderComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    RenderComponent::RenderComponent(std::string assetName, std::string path, const Vector2D& size, RenderPriority priority)
        : IRenderableComponent(priority, size)
        , mAssetName(assetName)
    {
        L_INFO("[RENDER COMPONENT]", "Creating Render Component with Asset Name: %s at Path: %s", assetName.c_str(), path.c_str());
        ServiceManager::GetServiceManager().GetRenderService().Register(this);
        ServiceManager::GetServiceManager().GetRenderService().RegisterAsset(assetName, path);
    }

    RenderComponent::RenderComponent(const RenderComponent &other)
        : IRenderableComponent(other.mPriority, other.mSize)
    {}

    RenderComponent::~RenderComponent() {}

    void RenderComponent::Render() {
        L_TRACE("[RENDER COMPONENT]", "Rendering Component");

        ServiceManager::GetServiceManager().GetRenderService().Render(mAssetName, mSize, mEntity->GetPosition());
    }
}