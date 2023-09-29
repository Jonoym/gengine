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
        void RegisterEntity(std::unique_ptr<Entity> entity);

    private:
        std::vector<std::unique_ptr<Entity>> mEntities;
        std::vector<std::unique_ptr<Entity>> mRegisterEntities;
    };
}