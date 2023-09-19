#include <graphics/controller/AnimationController.h>
#include <core/Logger.h>

namespace Gengine
{
    AnimationController::AnimationController(const std::string& assetName, const std::string& texturePath, const std::string& atlasPath, const Vector2D& size)
        : mAnimateComponent(assetName, texturePath, atlasPath, size)
    {
        L_INFO("[ANIMATION CONTROLLER]", "Constructing Animation Controller Component");
    }

    AnimationController::~AnimationController() {}

    void AnimationController::AddAnimation(const std::string& animationName, uint32 delayTime, AnimationPlaythrough playthrough)
    {
        L_INFO("[ANIMATION CONTROLLER]", "Adding Animation with the Name: '%s'", animationName.c_str());
        mAnimateComponent.AddAnimation(animationName, delayTime, playthrough);
    }

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