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
    }

    void ButtonAnimationController::OnHoverStart()
    {
        mAnimationComponent.StartAnimation("hoverStart", false);
    }

    void ButtonAnimationController::OnClick()
    {
        mAnimationComponent.StartAnimation("onClick", true);
    }

    void ButtonAnimationController::OnHoverExit()
    {
        mAnimationComponent.StartAnimation("hoverEnd", false);
    }

}