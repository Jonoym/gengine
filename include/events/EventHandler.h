#pragma once

#include <Includes.h>
#include <functional>

namespace Gengine
{
    class Entity;

    using Callback = std::function<void()>;
    using EntityCallback = std::function<void(Entity*, Entity*)>;

    class EventHandler
    {

    public:

        EventHandler();
        ~EventHandler();

        void AddListener(const std::string& eventName, Callback listener);
        // void AddListener(const std::string& eventName, EntityCallback listener);

        void Trigger(const std::string& eventName);
        void Trigger(const std::string& eventName, Entity* e1, Entity* e2);

    private:                
        std::unordered_map<std::string, std::vector<Callback>> mListeners;
        std::unordered_map<std::string, std::vector<EntityCallback>> mEntityListeners;
    };
        
}