#pragma once

#include <input/InputComponent.h>
#include <graphics/camera/CameraFocusComponent.h>
#include <utils/Vector2D.h>
#include <utils/Box2D.h>

namespace Gengine
{


    class Camera : public InputComponent
    {
    public:
        Camera();
        ~Camera();

        void Update() override;

        void SetAnchor(const Vector2D &anchorPosition);
        void SetTarget(CameraFocusComponent *cameraComponent, CameraState state);
        const Box2D GetWindowPosition();
        bool HandleInput(const Input &input) override;

    private:
        int32 mScreenWidth = 0;
        int32 mScreenHeight = 0;
        Vector2D mAnchorPosition;
        CameraState mState;
        Entity *mTrackingEntity = nullptr;

        int16 BUFFER_SIZE = 50;
        std::deque<Vector2D> mPositions;
        Vector2D mAverage;
    };
}