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

    void EventHandler::Trigger(const std::string &eventName, Event &event)
    {
        L_TRACE("[EVENT HANDLER]", "Triggering Event with Name: { '%s' }", eventName.c_str());

        auto listeners = mListeners.find(eventName);
        if (listeners != mListeners.end())
        {
            for (auto &listener : listeners->second)
            {
                listener(&event);
            }
        }
    }
}
