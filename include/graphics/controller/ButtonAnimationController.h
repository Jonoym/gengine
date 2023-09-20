#pragma once

#include <graphics/controller/AnimationController.h>

namespace Gengine
{
    class ButtonAnimationController : public AnimationController
    {
    public:
        ButtonAnimationController(const std::string& assetName, const std::string& texturePath, const std::string& atlasPath, const Vector2D& size);

        void Create() override;
    private:
        void OnHoverStart();
        void OnClick();
        void OnHoverExit();
    };
}