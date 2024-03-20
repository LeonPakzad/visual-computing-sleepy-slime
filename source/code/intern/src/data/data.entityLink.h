#pragma once

namespace Data
{
    class CEntity;
}

namespace Data
{
    class CEntityLink
    {
        public:
            static CEntity& GetEntity(CEntityLink& _Link, const CEntityLink CEntity::* MTR);
            static const CEntity& GetEntity(const CEntityLink& _Link, const CEntityLink CEntity::* MTR);

        public:
            CEntityLink();

        public:
            void Link(CEntityLink& _NextLink);
            void Unlink();

            bool IsLinked() const;

        public:
            CEntity& GetEntity();
            const CEntity& GetEntity() const;

        public:
            void SetNext(CEntityLink* _Link);
            CEntityLink* GetNext();

            void SetPrevious(CEntityLink* _Link);
            CEntityLink* GetPrevious();

        private:
            CEntityLink* m_Next;
            CEntityLink* m_Previous;
    };
}
