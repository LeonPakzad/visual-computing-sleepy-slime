#pragma once

#include "data.entityCategory.h"
#include "data.entityIterator.h"
#include "data.sector.h"

#include "../core/core.aabb.h"

namespace Data
{
    class CMap
    {
        public:
            CEntityIterator BeginEntity(Core::AABB2Float& _rAABB, SEntityCategory::ECategories _Category);
            CEntityIterator NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB, SEntityCategory::ECategories _Category);

            CEntityIterator BeginEntity(Core::AABB2Float& _rAABB);
            CEntityIterator NextEntity(CEntityIterator _Where, Core::AABB2Float& _rAABB);

            CEntityIterator EndEntity();

        private:
            CSector m_Sectors[4 * 8];
    };
}

