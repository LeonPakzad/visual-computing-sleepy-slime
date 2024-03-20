#include "data.eventSystem.h"

#include <iostream>
#include <cassert>

namespace Data 
{
    CEventSystem::CEventSystem() {}
    CEventSystem::~CEventSystem() {}

    void CEventSystem::Register(SEventType::EEvents _Type, EventListener _Listener)
    {
        m_EventListeners.push_back(std::make_pair(_Type, _Listener));
    }

    void CEventSystem::Unregister(SEventType::EEvents _Type, EventListener _Listener)
    {
        for (auto it = m_EventListeners.begin(); it != m_EventListeners.end(); ++it)
        {
            if (it->first == _Type && it->second == _Listener)
            {
                m_EventListeners.erase(it);
                return;
            }
        }
    }

    void CEventSystem::FireEvent(SEventType::EEvents _Type)
    {
        CEvent* event = nullptr;

        try
        {
            CEvent* event = new CEvent();
            event->SetType(_Type);

            FireEvent(*event);
        }
        catch (...)
        {
            std::cout << "Exception occured" << std::endl;
            delete event;
        }        
    }

    void CEventSystem::FireEvent(SEventType::EEvents _Type, int _Data)
    {
        CEvent* event = nullptr;

        try
        {
            CEvent* event = new CEvent();
            event->SetType(_Type);
            event->SetData(_Data);

            FireEvent(*event);
        }
        catch (...)
        {
            std::cout << "Exception occured" << std::endl;
            delete event;
        }        
    }

    void CEventSystem::FireEvent(CEvent& _pEvent)
    {
        for(auto& listener : m_EventListeners)
        {
            if (listener.first == _pEvent.GetType())
            {
                (*listener.second)(_pEvent);
            }
        }
    }

    void CEventSystem::AddEvent(CEvent& _pEvent)
    {
        m_Events.push_back(_pEvent);
    }

    void CEventSystem::ProcessEvents()
    {
        for (auto& event : m_Events)
        {
            FireEvent(event);
        }
    }
}