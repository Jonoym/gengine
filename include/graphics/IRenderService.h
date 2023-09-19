#pragma once

#include <Includes.h>
#include <services/IService.h>
#include <utils/Vector2D.h>
#include <graphics/IRenderableComponent.h>
#include <graphics/RenderComponent.h>

namespace Gengine
{
    struct IRenderService : public IService
    {
        virtual void Update() = 0;
        virtual void Dispose() = 0;
        virtual void OrderTextures() = 0;
        virtual void Render(const std::string &assetName, const Vector2D& size, const Vector2D &position, const Vector2D& clipSize, const Vector2D &clipPosition) = 0;
        virtual void RegisterAsset(const std::string& assetName, const std::string& path) = 0;
        virtual void RegisterAnimation(const std::string& assetName, const std::string& path) = 0;
        virtual void Register(IRenderableComponent* component) = 0;

        std::vector<IRenderableComponent*> mRenderComponents;
    };
}