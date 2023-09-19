#pragma once

#include <graphics/IRenderableComponent.h>
#include <components/Component.h>
#include <utils/Vector2D.h>
#include <utils/Box2D.h>
#include <utils/AtlasReader.h>

namespace Gengine
{
    enum class AnimationDuration
    {
        LOOP,
        NORMAL
    };

    struct AnimationFrame
    {
        std::string mAnimationName = "";
        uint32 mStartTime = 0;
        uint8 mFrameIndex = 0;
        uint32 mDelayTime = 0;
        std::vector<Box2D>* mAnimationFrames;
    };

    class AnimateComponent : public IRenderableComponent
    {
    public:
        AnimateComponent(const std::string &assetName, const std::string& texturePath, const std::string &atlasPath, const Vector2D &size);
        AnimateComponent(const AnimateComponent &other);
        ~AnimateComponent();

        void Load(const std::string &atlasPath);
        void AddAnimation(const std::string &animationName, uint32 delayTime);
        void StartAnimation(const std::string &animationName, bool force);

        const Vector2D &GetSize() override;
        void UpdateSize(const Vector2D &size);

        void Render() override;
        Vector2D mSize;

    private:
        std::string mAssetName;
        std::unordered_map<std::string, std::pair<uint32, std::vector<Box2D>>> mAnimations;

        AnimationFrame mCurrentAnimation;
    };
}