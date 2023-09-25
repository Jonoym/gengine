#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <gui/Interface.h>
#include <graphics/IRenderService.h>
#include <graphics/Texture.h>
#include <utils/AtlasReader.h>
#include <utils/Box2D.h>

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
        
        void Render(const std::string &assetName, const Vector2D &size, const Vector2D &position, const Vector2D &clipSize = Vector2D(), const Vector2D &clipPosition = Vector2D()) override;
        void RenderDebug(DebugColour lineColour, BoundType boundType, const Box2D& bounds) override;
        void RenderCircle(const Box2D& bounds);

        void RegisterAsset(const std::string &assetName, const std::string &path) override;
        void RegisterAnimation(const std::string &assetName, const std::string &path) override;
        std::vector<Box2D> *GetAnimation(const std::string &assetName, const std::string &animationName);

        void Register(IRenderableComponent *component) override;
        void RegisterDebug(IDebugRenderableComponent *component) override;

    protected:
        SDL_Renderer *mRenderer;
    private:
        std::unordered_map<std::string, Texture> mAssets;
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<Box2D>>> mSpritesheets;
    };
}