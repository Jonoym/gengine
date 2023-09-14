#pragma once

#include <Includes.h>
#include <services/IService.h>

namespace Gengine
{
    class EntityService : public IService
    {
        public:
        EntityService();
        ~EntityService();

        void Update() override;
    };
}