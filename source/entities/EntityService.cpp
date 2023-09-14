#include <entities/EntityService.h>

namespace Gengine
{
    EntityService::EntityService() {}

    EntityService::~EntityService() {}

    void EntityService::Update() {
    }

    void EntityService::Dispose() {
        
    }

    void EntityService::RegisterEntity(Entity& entity) {
        mEntities.push_back(entity);
    }

}