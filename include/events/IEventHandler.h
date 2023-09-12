#pragma once

#include <Includes.h>

namespace Gengine
{
    struct IEventHandler {

        virtual ~IEventHandler() = 0;
        virtual void AddListener(const std::string& eventName) = 0;

    };
}