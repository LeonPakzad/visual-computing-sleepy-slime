#pragma once

namespace Data
{
    class CEntity;
    class CEntityLink;
    class CEntityList;
}

namespace Data
{
    class CEntityIterator
    {
        public:
            CEntityIterator();
            CEntityIterator(const CEntityIterator& _pOther);

        public:
            CEntity& operator * ();
            CEntity* operator -> ();

        private:
            CEntityLink* m_Link;

        private:
            CEntityIterator(CEntityLink* _Link);

        private:
            friend class CEntityList;
    };
}
