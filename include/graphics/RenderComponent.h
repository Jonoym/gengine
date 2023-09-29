#pragma once

#include <graphics/IRenderableComponent.h>
#include <graphics/IDebugRenderableComponent.h>

namespace Gengine
{
    class RenderComponent : public IRenderableComponent, IDebugRenderableComponent
    {
    public:
        RenderComponent(std::string assetName, std::string path, const Vector2D &size, RenderPriority priority);
        RenderComponent(const RenderComponent &other);
        ~RenderComponent();

        void Dispose() override;
        void Render() override;
        void RenderDebug() override;

    private:
        std::string mAssetName;
    };
}