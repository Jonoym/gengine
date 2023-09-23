#include <graphics/controller/ButtonAnimationController.h>
#include <entities/Entity.h>

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
                                           { OnHoverStart(); });
        mEntity->mEventHandler.AddListener("onClick", [this](Event *event)
                                           { OnClick(); });
        mEntity->mEventHandler.AddListener("hoverEnd", [this](Event *event)
                                           { OnHoverExit(); });

        mAnimateComponent.StartAnimation("default", false);
    }

    void ButtonAnimationController::OnHoverStart()
    {
        mAnimateComponent.StartAnimation("hoverStart", false);
    }

    void ButtonAnimationController::OnClick()
    {
        mAnimateComponent.StartAnimation("onClick", true);
    }

    void ButtonAnimationController::OnHoverExit()
    {
        mAnimateComponent.StartAnimation("hoverEnd", false);
    }

}