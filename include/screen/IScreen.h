#pragma once

#include <Includes.h>

namespace Gengine 
{
    struct IScreen
    {
        virtual bool Initialise() = 0;
        virtual void Exit() = 0;
    };
}