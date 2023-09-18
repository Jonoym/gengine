#pragma once

#include <Includes.h>

namespace Gengine 
{
    class Entity;

    struct Component {

        virtual void Create() {}
        virtual void Update() {}
        virtual void Dispose() {}

        void Attach(Entity* entity) {
            mEntity = entity;
        }

        Entity* mEntity;
    };
}