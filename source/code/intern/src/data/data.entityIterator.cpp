
#include "data.entityIterator.h"
#include "data.entityLink.h"

#include <assert.h>

namespace Data
{
    CEntityIterator::CEntityIterator()
        : m_Link(nullptr) {}

    // -----------------------------------------------------------------------------

    CEntityIterator::CEntityIterator(const CEntityIterator& _Other)
        : m_Link(_Other.m_Link) {}

    // -----------------------------------------------------------------------------

    CEntityIterator::CEntityIterator(CEntityLink* _Link)
        : m_Link(_Link)
    {
    }

    // -----------------------------------------------------------------------------

    CEntity& CEntityIterator::operator * ()
    {
        assert(m_Link != nullptr);

        return m_Link->GetEntity();
    }

    // -----------------------------------------------------------------------------

    CEntity* CEntityIterator::operator -> ()
    {
        assert(m_Link != nullptr);

        return &m_Link->GetEntity();
    }
}
