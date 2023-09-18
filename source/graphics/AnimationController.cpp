#include <graphics/controller/AnimationController.h>
#include <core/Logger.h>

namespace Gengine
{
    AnimationController::AnimationController(const std::string& assetName, const std::string& path, const Vector2D& size)
        : mAnimateComponent(assetName, path, size)
    {
        L_INFO("[ANIMATION CONTROLLER]", "Constructing Animation Controller Component");
    }

    AnimationController::~AnimationController() {}

    void AnimationController::Create()
    {
        L_INFO("[ANIMATION CONTROLLER]", "Attaching Animate Component to the Entity");

        mAnimateComponent.Attach(mEntity);
    }

    void AnimationController::Dispose()
    {
        mAnimateComponent.Dispose();
    }
}