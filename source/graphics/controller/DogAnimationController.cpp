#include <entities/Entity.h>
#include <events/EventTypes.h>
#include <graphics/controller/DogAnimationController.h>

namespace Gengine
{
    DogAnimationController::DogAnimationController(const std::string &assetName, const std::string &texturePath, const std::string &atlasPath, const Vector2D &size)
        : AnimationController(assetName, texturePath, atlasPath, size, RenderPriority::ENTITY)
    {
    }

    void DogAnimationController::Create()
    {
        AnimationController::Create();

        mEntity->mEventHandler.AddListener("animateLeftStart", [this](Event *event)
                                           { MoveLeftStart(event); });
        mEntity->mEventHandler.AddListener("animateRightStart", [this](Event *event)
                                           { MoveRightStart(event); });
        mEntity->mEventHandler.AddListener("animateUpStart", [this](Event *event)
                                           { MoveUpStart(event); });
        mEntity->mEventHandler.AddListener("animateDownStart", [this](Event *event)
                                           { MoveDownStart(event); });
        mEntity->mEventHandler.AddListener("animateLeftEnd", [this](Event *event)
                                           { MoveLeftEnd(event); });
        mEntity->mEventHandler.AddListener("animateRightEnd", [this](Event *event)
                                           { MoveRightEnd(event); });
        mEntity->mEventHandler.AddListener("animateUpEnd", [this](Event *event)
                                           { MoveUpEnd(event); });
        mEntity->mEventHandler.AddListener("animateDownEnd", [this](Event *event)
                                           { MoveDownEnd(event); });
    }

    void DogAnimationController::MoveLeftStart(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("moveLeftStart", false);
    }

    void DogAnimationController::MoveRightStart(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("moveRightStart", false);
    }

    void DogAnimationController::MoveUpStart(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("moveUpStart", false);
    }

    void DogAnimationController::MoveDownStart(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("moveDownStart", false);
    }

    void DogAnimationController::MoveLeftEnd(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("defaultLeft", false);
    }

    void DogAnimationController::MoveRightEnd(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("defaultRight", false);
    }

    void DogAnimationController::MoveUpEnd(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("defaultUp", false);
    }

    void DogAnimationController::MoveDownEnd(Event *event)
    {
        AnimateEvent *animateEvent = dynamic_cast<AnimateEvent *>(event);
        if (animateEvent != nullptr)
            mAnimationComponent.StartAnimation("defaultDown", false);
    }
}