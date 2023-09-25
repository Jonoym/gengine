#pragma once

#include <graphics/IRenderableComponent.h>
#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class RenderComponent : protected IRenderableComponent
    {
    public:
        RenderComponent(std::string assetName, std::string path, const Vector2D &size, RenderPriority priority);
        RenderComponent(const RenderComponent &other);
        ~RenderComponent();

        void Render() override;
        Vector2D mSize;

    private:
        std::string mAssetName;
    };
}