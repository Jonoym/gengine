#include <graphics/controller/ButtonAnimationController.h>
#include <entities/Entity.h>
void OnHover();
void OnSelect();
void OnHoverExit();

namespace Gengine
{
    ButtonAnimationController::ButtonAnimationController(const std::string &assetName, const std::string &texturePath, const std::string &atlasPath, const Vector2D &size)
        : AnimationController(assetName, texturePath, atlasPath, size)
    {
    }

    void ButtonAnimationController::Create()
    {
        AnimationController::Create();

        mEntity->mEventHandler.AddListener("hoverStart", std::bind(&Gengine::ButtonAnimationController::OnHoverStart, this));
        mEntity->mEventHandler.AddListener("onClick", std::bind(&Gengine::ButtonAnimationController::OnClick, this));
        mEntity->mEventHandler.AddListener("hoverEnd", std::bind(&Gengine::ButtonAnimationController::OnHoverExit, this));

        mAnimateComponent.StartAnimation("default", false);
    }

    void ButtonAnimationController::OnHoverStart()
    {
        mAnimateComponent.StartAnimation("hoverStart", true);
    }

    void ButtonAnimationController::OnClick()
    {
        mAnimateComponent.StartAnimation("onClick", true);
    }

    void ButtonAnimationController::OnHoverExit()
    {
        mAnimateComponent.StartAnimation("hoverEnd", true);
    }

}