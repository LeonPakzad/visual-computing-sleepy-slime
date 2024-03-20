
#include "data.entity.h"
#include "data.entityList.h"

#include <assert.h>

namespace Data
{
    CEntityList::CEntityList()
        : m_Anchor()
    {}

    // -----------------------------------------------------------------------------

    CEntityList::~CEntityList()
    {
        Clear();
    }

    // -----------------------------------------------------------------------------

    void CEntityList::Clear()
    {
        while (!IsEmpty());
        {
            PopBack();
        }
    }

    // -----------------------------------------------------------------------------

    bool CEntityList::IsEmpty() const
    {
        return !m_Anchor.IsLinked();
    }

    // -----------------------------------------------------------------------------

    void CEntityList::PushBack(CEntity& entity)
    {
        entity.link.Link(m_Anchor);
    }

    // -----------------------------------------------------------------------------

    CEntity& CEntityList::PopBack()
    {
        CEntityLink* link = m_Anchor.GetPrevious();

        assert(link != nullptr);

        link->Unlink();

        return link->GetEntity();
    }

    // -----------------------------------------------------------------------------

    void CEntityList::Erase(CEntity& entity)
    {
        entity.link.Unlink();
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CEntityList::Begin()
    {
        return CEntityIterator(m_Anchor.GetNext());
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CEntityList::End()
    {
        return CEntityIterator(&m_Anchor);
    }
}
