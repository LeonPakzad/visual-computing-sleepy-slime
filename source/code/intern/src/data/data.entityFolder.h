#pragma once

#include "data.entityList.h"

namespace Data
{
    class CEntity;
    class CSector;
}

namespace Data
{
    class CEntityFolder
    {
        public:
            void AddEntity(CEntity& _Entity);
            void RemoveEntity(CEntity& _Entity);

        private:
            CSector*    m_Owner;
            CEntityList m_Entities;
    };
}
