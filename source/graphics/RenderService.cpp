#include <graphics/RenderService.h>

namespace Gengine {
    RenderService::RenderService() {}

    RenderService::~RenderService() {}

    void RenderService::Update() {}

    void RenderService::Render(const std::string &assetName, const Gengine::Vector2D &position) {}

    void RenderService::RegisterAsset(const std::string &assetName, const std::string &path) {}
}