#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <gui/Interface.h>
#include <graphics/IRenderService.h>
#include <graphics/Texture.h>

namespace Gengine
{
    class RenderService : public IRenderService
    {
    public:
        RenderService();
        ~RenderService();

        void Update() override;
        void Dispose() override;
        void OrderTextures() override;
        void Render(const std::string &assetName, const Vector2D& size, const Vector2D &position, const Vector2D& clipSize = Vector2D(), const Vector2D &clipPosition = Vector2D()) override;
        void RegisterAsset(const std::string &assetName, const std::string &path) override;
        void Register(IRenderableComponent* component) override;

    private:
        SDL_Renderer* mRenderer;
        std::unordered_map<std::string, Texture> mAssets;
    };
}