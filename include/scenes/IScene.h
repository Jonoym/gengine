#pragma once

#include <Includes.h>

namespace Gengine {

    struct IScene {

        virtual void Create() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

    };

}