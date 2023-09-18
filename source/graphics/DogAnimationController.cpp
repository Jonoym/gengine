#include <graphics/controller/DogAnimationController.h>
#include <entities/Entity.h>

namespace Gengine
{
    DogAnimationController::DogAnimationController(const std::string& assetName, const std::string& path, const Vector2D& size)
        : AnimationController(assetName, path, size)
        {}

    void DogAnimationController::Create()
    {
        AnimationController::Create();

        mEntity->mEventHandler.AddListener("moveLeftStart", std::bind(&Gengine::DogAnimationController::MoveLeftStart, this));
        mEntity->mEventHandler.AddListener("moveRightStart", std::bind(&Gengine::DogAnimationController::MoveRightStart, this));
        mEntity->mEventHandler.AddListener("moveUpStart", std::bind(&Gengine::DogAnimationController::MoveUpStart, this));
        mEntity->mEventHandler.AddListener("moveDownStart", std::bind(&Gengine::DogAnimationController::MoveDownStart, this));
        mEntity->mEventHandler.AddListener("moveLeftEnd", std::bind(&Gengine::DogAnimationController::MoveLeftEnd, this));
        mEntity->mEventHandler.AddListener("moveRightEnd", std::bind(&Gengine::DogAnimationController::MoveRightEnd, this));
        mEntity->mEventHandler.AddListener("moveUpEnd", std::bind(&Gengine::DogAnimationController::MoveUpEnd, this));
        mEntity->mEventHandler.AddListener("moveDownEnd", std::bind(&Gengine::DogAnimationController::MoveDownEnd, this));

        mAnimateComponent.StartAnimation("default", false);
    }

    void DogAnimationController::MoveLeftStart()
    {
        mAnimateComponent.StartAnimation("moveLeftStart", false);
    }

    void DogAnimationController::MoveRightStart()
    {
        mAnimateComponent.StartAnimation("moveRightStart", false);
    }

    void DogAnimationController::MoveUpStart()
    {
        mAnimateComponent.StartAnimation("moveUpStart", false);
    }

    void DogAnimationController::MoveDownStart()
    {
        mAnimateComponent.StartAnimation("moveDownStart", false);
    }

    void DogAnimationController::MoveLeftEnd()
    {
        mAnimateComponent.StartAnimation("defaultLeft", false);
    }

    void DogAnimationController::MoveRightEnd()
    {
        mAnimateComponent.StartAnimation("defaultRight", false);
    }

    void DogAnimationController::MoveUpEnd()
    {
        mAnimateComponent.StartAnimation("defaultUp", false);
    }

    void DogAnimationController::MoveDownEnd()
    {
        mAnimateComponent.StartAnimation("defaultDown", false);
    }
}