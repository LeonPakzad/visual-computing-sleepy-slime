#pragma once

#include <tinyxml2.h>

#include "../core/core.idManager.h"
#include "../core/core.itemManager.h"

#include "data.metaEntity.h"

namespace Data 
{
    class CMetaEntitySystem
    {
        public:
            static CMetaEntitySystem& GetInstance()
            {
                static CMetaEntitySystem instance;
                return instance;
            }

            CMetaEntitySystem(const CMetaEntitySystem&) = delete;
            CMetaEntitySystem& operator = (const CMetaEntitySystem&) = delete;
            
        public:
            int Initialize(tinyxml2::XMLDocument& _pDocument);

            Core::CIDManager::BID GetMetaEntityId(std::string _Name);
            CMetaEntity& GetMetaEntityById(Core::CIDManager::BID _ID);

        private:
            CMetaEntitySystem() {}

        private:
            Core::CIDManager m_IDManager;
            Core::CItemManager<CMetaEntity> m_ItemManager;
    };
}