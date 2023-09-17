#include <graphics/RenderComponent.h>
#include <services/ServiceManager.h>
#include <core/Logger.h>

namespace Gengine
{
    RenderComponent::RenderComponent(std::string assetName, std::string path, const Vector2D& size)
        : mAssetName(assetName)
        , mSize(size) 
    {
        L_INFO("[RENDER COMPONENT]", "Creating Render Component with Asset Name: %s at Path: %s", assetName.c_str(), path.c_str());
        ServiceManager::GetServiceManager().GetRenderService().RegisterAsset(assetName, path);
    }

    RenderComponent::RenderComponent(const RenderComponent &other) {}

    RenderComponent::~RenderComponent() {}

    void RenderComponent::Create() {}

    void RenderComponent::Update() {}
    
    void RenderComponent::Dispose() {}

    void RenderComponent::UpdateSize(const Vector2D& size) {
        mSize = size;
    }

    const Vector2D& RenderComponent::GetSize()
    {
        return mSize;
    }

    void RenderComponent::Render() {
        L_TRACE("[RENDER COMPONENT]", "Rendering Component");

        ServiceManager::GetServiceManager().GetRenderService().Render(mAssetName, mSize, mEntity->GetPosition());
    }
}