
#pragma once

#include "data.entityLink.h"
#include "data.metaEntity.h"
#include "data.entityCategory.h"

#include "../core/core.vector2.h"
#include "../core/core.idManager.h"
#include <array>

namespace Data
{
    class CEntityList;
}

namespace Data
{
    class CEntity
    {
        public:
            enum EFacet
            {
                GraphicsFacet,
                LogicFacet,
                NumberOfFacets
            };

        public:
            void SetFacet(EFacet type, void* facet);
            void* GetFacet(EFacet type);

        public:
            Core::CIDManager::BID id;
            SEntityCategory::ECategories category;
            Core::CVector2<float> position;
            Core::CVector2<float> direction;
            Core::CVector2<float> destination;
            Core::CVector2<float> size;
            Core::CAABB2<float> aabb;
            CMetaEntity* metaEntity;

        private:
            using FacetArray = std::array<void*, NumberOfFacets>;

        private:
            FacetArray facets;
            CEntityLink link;

        private:
            friend class CEntityLink;
            friend class CEntityList;
    };
}
