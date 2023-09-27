#include <core/Logger.h>
#include <graphics/camera/Camera.h>
#include <entities/Entity.h>
#include <input/ApplicationInput.h>
#include <services/ServiceManager.h>

namespace Gengine
{
    Camera::Camera()
        : InputComponent(InputPriority::OVERLAY), mState(CameraState::STATIC), mAnchorPosition(Vector2D())
    {
        L_INFO("[CAMERA]", "Creating Camera Component");

        SDL_GetWindowSize(Interface::GetInterface().GetWindow(), &mScreenWidth, &mScreenHeight);
    }

    Camera::~Camera()
    {
    }

    void Camera::Update()
    {
        mPositions.push_front(mTrackingEntity->mPosition);
        Vector2D removed = mPositions.back();
        mPositions.pop_back();

        mAverage += ((mTrackingEntity->mPosition - removed) / BUFFER_SIZE);
    }

    void Camera::SetAnchor(const Vector2D &anchorPosition)
    {
        L_INFO("[CAMERA]", "Setting Anchor to Position: { x: %f, y: %f }", anchorPosition.mX, anchorPosition.mY);

        mState = CameraState::STATIC;
        mAnchorPosition = anchorPosition;
    }

    void Camera::SetTarget(CameraFocusComponent *cameraComponent, CameraState state)
    {
        L_INFO("[CAMERA]", "Setting Camera Target to Tracking");

        mState = state;
        mTrackingEntity = cameraComponent->mEntity;
        if (state == CameraState::TRACKING_SMOOTH)
        {
            mPositions.clear();
            while (mPositions.size() < BUFFER_SIZE)
            {
                mPositions.push_front(mTrackingEntity->mPosition);
            }
            mAverage = mTrackingEntity->mPosition;
        }
    }

    const Box2D Camera::GetWindowPosition()
    {
        L_TRACE("[CAMERA]", "Getting Window Position");

        switch (mState)
        {
        case CameraState::STATIC:
            L_TRACE("[CAMERA]", "Camera Position is currently Static Position: { x: %f, y: %f, w:%d, h:%d }", mAnchorPosition.mX,
                    mAnchorPosition.mY, mScreenWidth, mScreenHeight);
            return Box2D(mAnchorPosition.mX, mAnchorPosition.mY, mScreenWidth, mScreenHeight);
        case CameraState::TRACKING:
            L_TRACE("[CAMERA]", "Camera Position is currently Tracking Position: { x: %f, y: %f, w:%d, h:%d }", mTrackingEntity->mPosition.mX - mScreenWidth / 2,
                    mTrackingEntity->mPosition.mY - mScreenHeight / 2, mScreenWidth, mScreenHeight);
            return Box2D(mTrackingEntity->mPosition.mX - mScreenWidth / 2,
                         mTrackingEntity->mPosition.mY - mScreenHeight / 2,
                         mScreenWidth, mScreenHeight);
        case CameraState::TRACKING_SMOOTH:
            L_TRACE("[CAMERA]", "Camera Position is currently Tracking Position: { x: %f, y: %f, w:%d, h:%d }", mTrackingEntity->mPosition.mX - mScreenWidth / 2,
                    mTrackingEntity->mPosition.mY - mScreenHeight / 2, mScreenWidth, mScreenHeight);

            return Box2D(mAverage.mX - mScreenWidth / 2,
                         mAverage.mY - mScreenHeight / 2,
                         mScreenWidth, mScreenHeight);
        }
        return Box2D();
    }

    bool Camera::HandleInput(const Input &input)
    {
        L_TRACE("[CAMERA]", "Handling Input");
        if (input.GetInputType() == InputType::WINDOW_RESIZE)
        {
            L_TRACE("[CAMERA]", "Input Type is Application Window Resize");
            const WindowResizeInput &resizeInput = dynamic_cast<const WindowResizeInput &>(input);

            mScreenWidth = resizeInput.GetWidth();
            mScreenHeight = resizeInput.GetHeight();

            return true;
        }
        return false;
    }

}