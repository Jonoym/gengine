#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IService{
        virtual void Update() = 0;
        virtual void Dispose() = 0;
    };
}