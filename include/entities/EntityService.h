#pragma once

#include <Includes.h>
#include <entities/Entity.h>
#include <services/IService.h>

namespace Gengine
{
    class EntityService : public IService
    {
    public:
        EntityService();
        ~EntityService();

        void Update() override;
        void Dispose() override;
        void RegisterEntity(Entity& entity);

    private:
        std::vector<Entity> mEntities;
    };
}