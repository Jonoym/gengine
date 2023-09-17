#pragma once

#include <Includes.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class AnimateService
    {
        void Update();
        void PlayAnimation(const std::string& assetName, const std::string& animationName, const Vector2D& position);
        void RegisterAsset(const std::string& assetName, const std::string& path);
    };
}