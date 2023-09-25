#include <maps/Map.h>
#include <services/ServiceManager.h>
#include <entities/Entity.h>
#include <input/InputMovementComponent.h>
#include <physics/components/MovementComponent.h>
#include <physics/components/CollisionComponent.h>
#include <graphics/controller/DogAnimationController.h>
#include <input/ButtonComponent.h>
#include <graphics/controller/ButtonAnimationController.h>

#include <core/Logger.h>

namespace Gengine
{
    Map::Map() {
    }

    Map::~Map() {}

    void Map::Initialise()
    {
        L_INFO("[MAP]", "Initialising Map Area");

        mTerrain.GenerateTerrain("Not Specified Yet");

        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->AddComponent(std::make_shared<InputMovementComponent>());
        entity->AddComponent(std::make_shared<MovementComponent>());
        entity->AddComponent(std::make_shared<CollisionComponent>(10.0f, 75.0f, PhysicsBody::RIGID));

        std::shared_ptr<DogAnimationController> aniController =
            std::make_shared<DogAnimationController>("bearAnimation", "assets/bearSprites.png", "assets/bear.atlas", Vector2D(200.0f, 200.0f));
        aniController->AddAnimation("moveLeftStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("moveRightStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("moveUpStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("defaultUp", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("moveDownStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("defaultLeft", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("defaultRight", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        aniController->AddAnimation("defaultDown", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        entity->AddComponent(aniController);

        SpawnEntityAt(std::move(entity), Vector2D(0.0f, 0.0f));

        // std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        // entity->AddComponent(std::make_shared<RenderComponent>("dog", "assets/dog.png", Vector2D(400.0f, 400.0f)));
        // entity->AddComponent(std::make_shared<InputMovementComponent>());
        // entity->AddComponent(std::make_shared<MovementComponent>());
        // entity->AddComponent(std::make_shared<CollisionComponent>(10.0f, 150.0f));
        // SpawnEntityAt(std::move(entity), Vector2D(0.0f, 0.0f));

        // for (float i = 0.0f; i < 2000; i += 200)
        // {
        //     for (float j = 0.0f; j < 1000; j += 200)
        //     {

        //         std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        //         entity2->AddComponent(std::make_shared<InputMovementComponent>());
        //         entity2->AddComponent(std::make_shared<MovementComponent>());
        //         entity2->AddComponent(std::make_shared<CollisionComponent>(1.0f, 75.0f));

        //         std::shared_ptr<DogAnimationController> aniController2 = std::make_shared<DogAnimationController>("bearAnimation", "assets/bearSprites.png", "assets/bear.atlas", Vector2D(200.0f, 200.0f));
        //         aniController2->AddAnimation("moveLeftStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("moveRightStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("moveUpStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("defaultUp", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("moveDownStart", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("defaultLeft", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("defaultRight", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("defaultDown", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         aniController2->AddAnimation("default", AnimationPlaythrough::LOOP, AnimationCompletion::CANCELLABLE, 100);
        //         entity2->AddComponent(aniController2);

        //         // std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        //         // entity2->AddComponent(std::make_shared<RenderComponent>("sheep", "assets/sheep.png", Vector2D(200.0f, 200.0f)));
        //         // // entity2->AddComponent(std::make_shared<MovementComponent>());
        //         // entity2->AddComponent(std::make_shared<CollisionComponent>(3.0f, 75.0f));
        //         SpawnEntityAt(std::move(entity2), Vector2D(400.0f + i, 400.0f + j));
        //     }
        // }

        std::unique_ptr<Entity> button = std::make_unique<Entity>();
        button->AddComponent(std::make_shared<ButtonComponent>(Vector2D(300.0f, 140.0f)));

        std::shared_ptr<ButtonAnimationController> buttonController =
            std::make_shared<ButtonAnimationController>("button", "assets/buttonSprites.png", "assets/button.atlas", Vector2D(300.0f, 140.0f));
        buttonController->AddAnimation("hoverStart", AnimationPlaythrough::NORMAL, AnimationCompletion::CANCELLABLE, 100);
        buttonController->AddAnimation("onClick", AnimationPlaythrough::NORMAL, AnimationCompletion::COMPLETE, 200);
        buttonController->AddAnimation("hoverEnd", AnimationPlaythrough::NORMAL, AnimationCompletion::CANCELLABLE, 100);
        button->AddComponent(buttonController);

        SpawnEntityAt(std::move(button), Vector2D(200.0f, 120.0f));
        

        // std::unique_ptr<Entity> button2 = std::make_unique<Entity>();
        // button2->AddComponent(std::make_shared<ButtonComponent>(Vector2D(600.0f, 280.0f)));

        // std::shared_ptr<ButtonAnimationController> buttonController2 =
        //     std::make_shared<ButtonAnimationController>("button", "assets/buttonSprites.png", "assets/button.atlas", Vector2D(600.0f, 280.0f));
        // buttonController2->AddAnimation("hoverStart", AnimationPlaythrough::NORMAL, AnimationCompletion::CANCELLABLE, 100);
        // buttonController2->AddAnimation("onClick", AnimationPlaythrough::NORMAL, AnimationCompletion::COMPLETE, 200);
        // buttonController2->AddAnimation("hoverEnd", AnimationPlaythrough::NORMAL, AnimationCompletion::CANCELLABLE, 100);
        // buttonController2->AddAnimation("default", AnimationPlaythrough::NORMAL, AnimationCompletion::CANCELLABLE, 100);
        // button2->AddComponent(buttonController2);

        // SpawnEntityAt(std::move(button2), Vector2D(1000.0f, 700.0f));
    }

    void Map::Dispose()
    {
        L_INFO("[MAP]", "Disposing Map Area");
    }

    void Map::SpawnEntityAt(std::unique_ptr<Entity> entity, const Vector2D &position)
    {
        L_INFO("[ENTITY]", "Spawning the Entity at Position: { x: %f, y: %f }", entity->mPosition.mX, entity->mPosition.mY);

        entity->SetPosition(position);
        ServiceManager::GetServiceManager().GetEntityService().RegisterEntity(std::move(entity));
    }

}