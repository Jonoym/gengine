#pragma once

#include <input/InputMouseComponent.h>
#include <utils/Box2D.h>
#include <entities/Entity.h>

namespace Gengine
{
    class ButtonComponent : public InputMouseComponent
    {
    public:
        ButtonComponent(const Vector2D& size);
        ~ButtonComponent();
        
    protected:
        void HandleMouseMoved(const Input &input) override;
        void HandleMouseButtonPressed(const Input &input) override;
        void HandleMouseButtonReleased(const Input &input) override;
    
    private:

        bool IsActive(int32 x, int32 y);

        Vector2D mSize;
        Box2D mBounds;
    };
}