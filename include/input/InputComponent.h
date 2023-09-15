#pragma once

#include <components/Component.h>

namespace Gengine
{
    class InputComponent
    {
        public:

        virtual void HandleInput() = 0;
        virtual bool ShouldQuit() = 0;
        virtual void Register(const std::shared_ptr<Component> component) = 0;
    };
}