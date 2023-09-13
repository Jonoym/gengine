#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IEventHandler {

        virtual void AddListener(const std::string& eventName) = 0;

    };
}