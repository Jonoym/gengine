#pragma once

#include <Includes.h>
#include <services/IService.h>
#include <utils/Vector2D.h>
#include <graphics/RenderComponent.h>

namespace Gengine
{
    class RenderService : public IService
    {
    public:
        RenderService();
        ~RenderService();

        void Update() override;
        void Dispose() override;
        void Render(const std::string& assetName, const Vector2D& position);
        void RegisterAsset(const std::string& assetName, const std::string& path);
        void Register(const RenderComponent& component);
    };
}