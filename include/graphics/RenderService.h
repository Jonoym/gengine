#pragma once

#include <Includes.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class RenderService
    {
    public:
        RenderService();
        ~RenderService();

        void Update();
        void Render(const std::string& assetName, const Vector2D& position);
        void RegisterAsset(const std::string& assetName, const std::string& path);
    };
}