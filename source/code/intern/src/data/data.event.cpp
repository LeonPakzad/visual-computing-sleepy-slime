#include "data.event.h"

namespace Data 
{
    void CEvent::SetType(SEventType::EEvents _Type)
    {
        this->m_Type = _Type;
    }

    SEventType::EEvents CEvent::GetType() const
    {
        return m_Type;
    }

    void CEvent::SetData(int _Data)
    {
        this->m_Data = _Data;
    }

    int CEvent::GetData() const
    {
        return m_Data;
    }
}