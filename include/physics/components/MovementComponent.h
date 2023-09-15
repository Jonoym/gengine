#pragma once

#include <components/Component.h>
#include <utils/Vector2D.h>

namespace Gengine
{
    class MovementComponent : public Component
    {
    public:

        MovementComponent();
        ~MovementComponent();

        void Create() override;
        void Update() override;
        void Dispose() override;

        void Trigger();
    
    };
}