#pragma once

#include "data.entityIterator.h"
#include "data.entityLink.h"

namespace Data
{
    class CEntityList
    {
        public:
            CEntityList();
           ~CEntityList();

        public:
            void Clear();
            bool IsEmpty() const;

        public:
            void PushBack(CEntity& m_Entity);
            CEntity& PopBack();

            void Erase(CEntity& m_Entity);

        public:
            CEntityIterator Begin();
            CEntityIterator End();

        private:
            CEntityLink m_Anchor;
    };
}
