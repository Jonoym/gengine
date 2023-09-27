#include <entities/Entity.h>
#include <events/EventTypes.h>
#include <graphics/controller/ButtonAnimationController.h>

namespace Gengine
{
    ButtonAnimationController::ButtonAnimationController(const std::string &assetName,
                                                         const std::string &texturePath,
                                                         const std::string &atlasPath,
                                                         const Vector2D &size)
        : AnimationController(assetName, texturePath, atlasPath, size, RenderPriority::OVERLAY)
    {
    }

    void ButtonAnimationController::Create()
    {
        AnimationController::Create();

        mEntity->mEventHandler.AddListener("hoverStart", [this](Event *event)
                                           { OnHoverStart(event); });
        mEntity->mEventHandler.AddListener("onClick", [this](Event *event)
                                           { OnClick(event); });
        mEntity->mEventHandler.AddListener("hoverEnd", [this](Event *event)
                                           { OnHoverExit(event); });
    }

    void ButtonAnimationController::OnHoverStart(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
        mAnimationComponent.StartAnimation("hoverStart", false);
    }

    void ButtonAnimationController::OnClick(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
        mAnimationComponent.StartAnimation("onClick", true);
    }

    void ButtonAnimationController::OnHoverExit(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
        mAnimationComponent.StartAnimation("hoverEnd", false);
    }

}