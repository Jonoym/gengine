#pragma once

#include <graphics/controller/AnimationController.h>

namespace Gengine
{
    class DogAnimationController : public AnimationController
    {
    public:
        DogAnimationController(const std::string& assetName, const std::string& texturePath, const std::string& atlasPath, const Vector2D& size);

        void Create() override;
    private:
        void MoveLeftStart(Event* event);
        void MoveRightStart(Event* event);
        void MoveUpStart(Event* event);
        void MoveDownStart(Event* event);
        void MoveLeftEnd(Event* event);
        void MoveRightEnd(Event* event);
        void MoveUpEnd(Event* event);
        void MoveDownEnd(Event* event);
    };
}