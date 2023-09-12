#pragma once

#include <Includes.h>

namespace Gengine 
{

    struct IComponent {

        virtual ~IComponent() = 0;

        virtual void Create() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;
    };
}