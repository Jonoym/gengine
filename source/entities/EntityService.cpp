#include <entities/EntityService.h>
#include <core/Logger.h>

namespace Gengine
{
    EntityService::EntityService() {}

    EntityService::~EntityService() {}

    void EntityService::Update() {
    }

    void EntityService::Dispose() {
        
    }

    void EntityService::RegisterEntity(std::unique_ptr<Entity> entity) {
        L_INFO("[ENTITY SERVICE]", "Registering Entity");
        mEntities.push_back(std::move(entity));
    }

}