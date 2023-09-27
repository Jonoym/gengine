#pragma once

#include <components/Component.h>

namespace Gengine
{
    enum class CameraState
    {
        TRACKING,
        STATIC,
        TRACKING_SMOOTH
    };

    class CameraFocusComponent : public Component
    {
    public:

        CameraFocusComponent(bool tracking, CameraState state);

        void Create();

        void StartTracking();
        void StopTracking();
    private:
        bool mTracking;
        CameraState mTrackingState;
    };
}