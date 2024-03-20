

#include "data.entity.h"
#include "data.entityLink.h"

#include <stdlib.h>

namespace Data
{
    CEntity& CEntityLink::GetEntity(CEntityLink& _Link, const CEntityLink CEntity::* _MTR)
    {
        return *reinterpret_cast<CEntity*>(reinterpret_cast<ptrdiff_t>(&_Link) - (reinterpret_cast<ptrdiff_t>(&(static_cast<CEntity*>(nullptr) ->*(_MTR))) - reinterpret_cast<ptrdiff_t>(static_cast<void*>(nullptr))));
    }

    // -----------------------------------------------------------------------------

    const CEntity& CEntityLink::GetEntity(const CEntityLink& _Link, const CEntityLink CEntity::* _MTR)
    {
        return *reinterpret_cast<CEntity*>(reinterpret_cast<ptrdiff_t>(&_Link) - (reinterpret_cast<ptrdiff_t>(&(static_cast<CEntity*>(nullptr) ->*(_MTR))) - reinterpret_cast<ptrdiff_t>(static_cast<void*>(nullptr))));
    }
}

namespace Data
{
    CEntityLink::CEntityLink()
    {
        m_Next     = this;
        m_Previous = this;
    }

    // -----------------------------------------------------------------------------

    void CEntityLink::Link(CEntityLink& _NextLink)
    {
        m_Next     = &_NextLink;
        m_Previous = _NextLink.m_Previous;

        _NextLink.m_Previous->m_Next = this;
        _NextLink.m_Previous       = this;
    }

    // -----------------------------------------------------------------------------

    void CEntityLink::Unlink()
    {
        m_Previous->m_Next = m_Next;
        m_Next->m_Previous = m_Previous;

        m_Next     = this;
        m_Previous = this;
    }

    // -----------------------------------------------------------------------------

    bool CEntityLink::IsLinked() const
    {
        return m_Next != m_Next->m_Next;
    }

    // -----------------------------------------------------------------------------

    CEntity& CEntityLink::GetEntity()
    {
        return GetEntity(*this, &CEntity::link);
    }

    // -----------------------------------------------------------------------------

    const CEntity& CEntityLink::GetEntity() const
    {
        return CEntityLink::GetEntity(*this, &CEntity::link);
    }

    // -----------------------------------------------------------------------------

    void CEntityLink::SetNext(CEntityLink* _Link)
    {
        m_Next = _Link;
    }

    // -----------------------------------------------------------------------------

    CEntityLink* CEntityLink::GetNext()
    {
        return m_Next;
    }

    // -----------------------------------------------------------------------------

    void CEntityLink::SetPrevious(CEntityLink* _Link)
    {
        m_Previous = _Link;
    }

    // -----------------------------------------------------------------------------

    CEntityLink* CEntityLink::GetPrevious()
    {
        return m_Previous;
    }
}
