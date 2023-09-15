#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class RenderComponent : public Component
    {
    public:

        RenderComponent();
        RenderComponent(std::string assetName, std::string path, const Vector2D& size);
        RenderComponent(const RenderComponent& other);
        ~RenderComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;
        void UpdateSize(const Vector2D& size);
    
        void Render();

    private:
        std::string mAssetName;
        Vector2D mSize;
    
    };
}