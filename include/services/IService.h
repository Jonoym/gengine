#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IService{
        virtual void Update() {}
        virtual void Dispose() {}
    };
}