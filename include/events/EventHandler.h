#pragma once

#include <events/IEventHandler.h>

namespace Gengine
{
    class EventHandler : public IEventHandler
    {
        void AddListener(const std::string& eventName) override;
    };
}