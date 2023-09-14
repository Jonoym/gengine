#pragma once

#include <Includes.h>

namespace Gengine {

    struct IScene {

        virtual void Initialise() = 0;
        virtual bool Update() = 0;
        virtual void Dispose() = 0;
    };
}