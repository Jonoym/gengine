#pragma once

#include <components/Component.h>

namespace Gengine
{
    class RenderComponent : public Component
    {
    public:

        RenderComponent();
        RenderComponent(const RenderComponent& other);
        ~RenderComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;
    
        void Render();

    private:
    
    };
}