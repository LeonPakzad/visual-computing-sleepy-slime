
#include "data.map.h"

namespace Data
{
    CEntityIterator CMap::BeginEntity(Core::AABB2Float& _rAABB, SEntityCategory::ECategories _Category)
    {
        // Get first sector within AABB which contains an entity within the entity list of the given category
        // return iterator to this entity, otherwise return end iterator


        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CMap::NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB, SEntityCategory::ECategories _Category)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CMap::BeginEntity(Core::AABB2Float& _rAABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CMap::NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    CEntityIterator CMap::EndEntity()
    {
        return CEntityIterator();
    }
}

