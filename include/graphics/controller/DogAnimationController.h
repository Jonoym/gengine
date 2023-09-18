#pragma once

#include <graphics/controller/AnimationController.h>

namespace Gengine
{
    class DogAnimationController : public AnimationController
    {
    public:
        DogAnimationController(const std::string& assetName, const std::string& path, const Vector2D& size);

        void Create() override;
    private:
        void MoveLeftStart();
        void MoveRightStart();
        void MoveUpStart();
        void MoveDownStart();
        void MoveLeftEnd();
        void MoveRightEnd();
        void MoveUpEnd();
        void MoveDownEnd();
    };
}