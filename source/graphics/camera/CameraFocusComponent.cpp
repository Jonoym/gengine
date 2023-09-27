#include <graphics/camera/CameraFocusComponent.h>
#include <core/Logger.h>
#include <services/ServiceManager.h>

namespace Gengine
{

    CameraFocusComponent::CameraFocusComponent(bool tracking, CameraState state)
        : mTracking(tracking)
        , mTrackingState(state)
    {
    }

    void CameraFocusComponent::Create()
    {
        if (mTracking)
        {
            StartTracking();
        }
    }

    void CameraFocusComponent::StartTracking()
    {
        L_INFO("[CAMERA FOCUS COMPONENT]", "Starting to Track");
        ServiceManager::GetServiceManager().GetRenderService().GetCamera()->SetTarget(this, mTrackingState);
    }

    void CameraFocusComponent::StopTracking()
    {
        L_INFO("[CAMERA FOCUS COMPONENT]", "Stopping Tracking");
        ServiceManager::GetServiceManager().GetRenderService().GetCamera()->SetAnchor(mEntity->mPosition);
    }
}