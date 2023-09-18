#include <entities/EntityService.h>
#include <core/Logger.h>

namespace Gengine
{
    EntityService::EntityService() {}

    EntityService::~EntityService() {}

    void EntityService::Update() {
        for (auto& entity : mEntities)
        {
            entity->Update();
        }
    }

    void EntityService::Dispose()
    {
        for (auto& entity : mEntities)
        {
            entity->Dispose();
        }
    }

    void EntityService::RegisterEntity(std::unique_ptr<Entity> entity) {
        L_INFO("[ENTITY SERVICE]", "Registering Entity");
        mEntities.push_back(std::move(entity));
    }

}