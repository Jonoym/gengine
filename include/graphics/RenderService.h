#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <gui/Interface.h>
#include <graphics/IRenderService.h>

namespace Gengine
{
    class RenderService : public IRenderService
    {
    public:
        RenderService();
        ~RenderService();

        void Update() override;
        void Dispose() override;
        void Render(const std::string &assetName, const Vector2D &position) override;
        void RegisterAsset(const std::string &assetName, const std::string &path) override;
        void Register(const std::shared_ptr<Component> component) override;

    private:
        SDL_Renderer* mRenderer;
        std::unordered_map<std::string, SDL_Texture*> mAssets;
    };
}