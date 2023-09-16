#include <events/EventHandler.h>
#include <core/Logger.h>

namespace Gengine
{
    EventHandler::EventHandler()
    {
    }

    EventHandler::~EventHandler()
    {
    }

    void EventHandler::AddListener(const std::string &eventName, Callback listener)
    {
        L_INFO("[EVENT HANDLER]", "Adding Listener with Name: { '%s' }", eventName.c_str());
        auto listeners = mListeners.find(eventName);
        if (listeners == mListeners.end())
        {
            mListeners.emplace(eventName, std::vector<Callback>({listener}));
        }
        else
        {
            listeners->second.push_back(listener);
        }
    }

    // void EventHandler::AddListener(const std::string &eventName, EntityCallback listener)
    // {
    //     L_INFO("[EVENT HANDLER]", "Adding Listener for Entities with Name: %s", eventName.c_str());
    //     auto listeners = mEntityListeners.find(eventName);
    //     if (listeners == mEntityListeners.end())
    //     {
    //         mEntityListeners.emplace(eventName, std::vector<EntityCallback>({listener}));
    //     }
    //     else
    //     {
    //         listeners->second.push_back(listener);
    //     }
    // }

    void EventHandler::Trigger(const std::string &eventName)
    {
        L_INFO("[EVENT HANDLER]", "Triggering Event with Name: { '%s' }", eventName.c_str());

        auto listeners = mListeners.find(eventName);
        if (listeners != mListeners.end())
        {
            for (auto& listener : listeners->second)
            {
                listener();
            }
        }
    }

    void EventHandler::Trigger(const std::string &eventName, Entity *e1, Entity *e2)
    {
        L_INFO("[EVENT HANDLER]", "Triggering Event with Name: %s", eventName.c_str());

        auto listeners = mEntityListeners.find(eventName);
        if (listeners != mEntityListeners.end())
        {
            for (auto& listener : listeners->second)
            {
                listener(e1, e2);
            }
        }
    }
}
