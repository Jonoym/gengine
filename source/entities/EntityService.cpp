#include <entities/EntityService.h>
#include <core/Logger.h>

namespace Gengine
{
    EntityService::EntityService() {}

    EntityService::~EntityService() {}

    void EntityService::Update() {
        L_TRACE("[ENTITY SERVICE]", "Updating all Entities");
        for (auto& entity : mEntities)
        {
            entity->Update();
        }
    }

    void EntityService::Dispose()
    {
        L_INFO("[ENTITY SERVICE]", "Disposing all Entities");
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