#pragma once

#include <Includes.h>
#include <components/IComponent.h>
#include <events/EventHandler.h>
#include <utils/Vector2D.h>

namespace Gengine 
{
    struct IEntity {

        virtual ~IEntity() = 0;

        virtual void SetPosition(const Vector2D& newPosition) = 0;
        virtual const Vector2D& GetPosition() = 0;

        Vector2D mPosition;
        EventHandler mEventHandler;
        std::vector<IComponent> mComponents;
    };
}