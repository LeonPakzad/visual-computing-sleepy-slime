#pragma once

#include <list>

#include "data.event.h"
#include "data.eventListener.h"
#include "data.eventType.h"

namespace Data
{
    using EventListenerPair = std::pair<SEventType::EEvents, EventListener>;
    using EventListenerList = std::list<EventListenerPair>;

    class CEventSystem
    {
        public:
            static CEventSystem& GetInstance()
            {
                static CEventSystem instance;
                return instance;
            };

        public:
            void Register(SEventType::EEvents _Type, EventListener _Listener);
            void Unregister(SEventType::EEvents _Type, EventListener _Listener);

        public:
            void FireEvent(CEvent& event);
            void FireEvent(SEventType::EEvents _Type);
            void FireEvent(SEventType::EEvents _Type, int _Data);

            void AddEvent(CEvent& _Event);
            void ProcessEvents();

        private:
            CEventSystem();
           ~CEventSystem();

        private:
            CEventSystem(const CEventSystem&) = delete;
            CEventSystem& operator = (const CEventSystem&) = delete;

            std::list<CEvent> m_Events;
            EventListenerList m_EventListeners;
    };
}
