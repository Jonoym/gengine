#pragma once

#include <input/IInputService.h>

namespace Gengine
{
    class InputService : public IInputService
    {
        void Update() override;
    };
}