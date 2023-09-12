#pragma once

#include <Includes.h>
#include <components/IComponent.h>
#include <events/EventHandler.h>

namespace Gengine 
{
    struct IEntity {

        virtual ~IEntity() = 0;

        EventHandler mEventHandler;
        std::vector<IComponent> mComponents;
    };
}