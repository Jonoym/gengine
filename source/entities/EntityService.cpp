#include <entities/EntityService.h>
#include <core/Logger.h>

namespace Gengine
{
    EntityService::EntityService() {}

    EntityService::~EntityService() {}

    void EntityService::Update() {
        if (!mRegisterEntities.empty())
        {
            L_INFO("[ENTITY SERVICE]", "Transferring Registered Entities to be Included in Updates");
            for (auto& entity : mRegisterEntities)
            {
                mEntities.push_back(std::move(entity));
            }
        }
        mRegisterEntities.clear();

        // L_TRACE("[ENTITY SERVICE]", "Deleting Entities for Disposal");
        // auto deleteIt = mEntities.begin();
        // while (deleteIt != mEntities.end())
        // {
        //     if (deleteIt->get()->ShouldDispose())
        //     {
        //         L_TRACE("[ENTITY SERVICE]", "Deleting Entity");
        //         deleteIt->get()->Dispose();
        //         deleteIt = mEntities.erase(deleteIt);
        //     }
        //     else
        //     {
        //         deleteIt++;
        //     }
        // }

        L_TRACE("[ENTITY SERVICE]", "Updating all Entities");
        for (auto& entity : mEntities)
        {
            L_TRACE("[ENTITY SERVICE]", "Updating Entity");
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
        mRegisterEntities.push_back(std::move(entity));
    }
}