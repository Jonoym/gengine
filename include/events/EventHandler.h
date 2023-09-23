#pragma once

#include <Includes.h>
#include <events/Event.h>
#include <functional>

namespace Gengine
{
    class Entity;

    using Callback = std::function<void(Event*)>;

    class EventHandler
    {

    public:

        EventHandler();
        ~EventHandler();

        void AddListener(const std::string& eventName, Callback listener);
        void Trigger(const std::string& eventName, Event& event);

    private:                
        std::unordered_map<std::string, std::vector<Callback>> mListeners;
    };
        
}