#pragma once

#include <Includes.h>

namespace Gengine 
{
    class Entity;

    struct Component {

        virtual void Create() = 0;
        virtual void Update() = 0;
        virtual void Dispose() = 0;

        void Attach(Entity* entity) {
            mEntity = entity;
        }

        Entity* mEntity;
    };
}