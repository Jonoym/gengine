#pragma once

#include <input/InputMouseComponent.h>
#include <utils/Box2D.h>
#include <entities/Entity.h>
#include <events/Event.h>

namespace Gengine
{
    class ButtonComponent : public InputMouseComponent
    {
    public:
        ButtonComponent(const Vector2D &size);
        ~ButtonComponent();

    protected:
        bool HandleMouseMoved(const Input &input) override;
        bool HandleMouseButtonPressed(const Input &input) override;
        bool HandleMouseButtonReleased(const Input &input) override;

        void HandleInactive(const Input &input) override;

    private:
        bool IsActive(int32 x, int32 y);
        
        bool mActive;
        Vector2D mSize;
        Box2D mBounds;
    };
}