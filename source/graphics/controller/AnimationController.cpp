#include <core/Logger.h>
#include <events/EventTypes.h>
#include <graphics/controller/AnimationController.h>

namespace Gengine
{
    AnimationController::AnimationController(const std::string &assetName,
                                             const std::string &texturePath,
                                             const std::string &atlasPath,
                                             const Vector2D &size,
                                             RenderPriority priority)
        : mAnimationComponent(assetName, texturePath, atlasPath, size, priority)
    {
        L_INFO("[ANIMATION CONTROLLER]", "Constructing Animation Controller Component");
    }

    AnimationController::~AnimationController() {}

    void AnimationController::AddAnimation(const std::string &animationName, AnimationPlaythrough playthrough, AnimationCompletion completion,  uint32 delayTime)
    {
        L_INFO("[ANIMATION CONTROLLER]", "Adding Animation with the Name: '%s'", animationName.c_str());
        mAnimationComponent.AddAnimation(animationName, playthrough, completion, delayTime);
    }

    void AnimationController::Create()
    {
        L_INFO("[ANIMATION CONTROLLER]", "Attaching Animate Component to the Entity");

        mAnimationComponent.Attach(mEntity);
        mAnimationComponent.Create();
    }

    void AnimationController::Dispose()
    {
        mAnimationComponent.Dispose();
    }
}