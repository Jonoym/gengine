#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IMap
    {
        virtual void Initialise() = 0;
        virtual void Dispose() = 0;
    };
}