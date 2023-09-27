#pragma once

#include <Includes.h>
#include <services/IService.h>
#include <utils/Vector2D.h>
#include <utils/Box2D.h>
#include <graphics/IRenderableComponent.h>
#include <graphics/IDebugRenderableComponent.h>
#include <graphics/Texture.h>
#include <graphics/camera/Camera.h>

namespace Gengine
{
    struct IRenderService : public IService
    {

        virtual void RegisterCamera(std::shared_ptr<Camera> camera) = 0;
        virtual Camera* GetCamera() = 0;

        virtual void Update() = 0;
        virtual void Dispose() = 0;
        virtual void OrderTextures() = 0;

        virtual void Render(const std::string &assetName, const Vector2D &size, const Vector2D &position, RenderPriority priority, const Vector2D &clipSize, const Vector2D &clipPosition) = 0;
        virtual void RenderDebug(DebugColour lineColour, BoundType boundType, const Box2D &bounds) = 0;

        virtual void RegisterAsset(const std::string &assetName, const std::string &path) = 0;
        virtual void RegisterAnimation(const std::string &assetName, const std::string &path) = 0;

        virtual void Register(IRenderableComponent *component) = 0;
        virtual void RegisterDebug(IDebugRenderableComponent *component) = 0;

        std::vector<IRenderableComponent *> mRenderComponents;
        std::vector<IDebugRenderableComponent *> mDebugComponents;
        std::unordered_map<std::string, Texture> mAssets;

        std::shared_ptr<Camera> mCamera = nullptr;
    };
}