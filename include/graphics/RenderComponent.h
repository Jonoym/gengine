#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class RenderComponent : public Component
    {
    public:
        RenderComponent(std::string assetName, std::string path, const Vector2D &size);
        RenderComponent(const RenderComponent &other);
        ~RenderComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;
        const Vector2D& GetSize();

        void UpdateSize(const Vector2D &size);

        void Render();
        Vector2D mSize;

    private:
        std::string mAssetName;
    };
}