#pragma once

#include "data.eventType.h"

namespace Data
{
    class CEvent
    {
        public:
            void SetType(SEventType::EEvents _Type);
            SEventType::EEvents GetType() const;

            void SetData(int _Data);
            int GetData() const;

        protected:
            SEventType::EEvents m_Type;
            int m_Data;
    };
}
