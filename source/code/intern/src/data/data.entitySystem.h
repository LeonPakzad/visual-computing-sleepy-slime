#pragma once

#include <tinyxml2.h>

#include "../core/core.idManager.h"
#include "../core/core.itemManager.h"
#include "data.entity.h"

using namespace tinyxml2;

namespace Data 
{
    class CEntitySystem 
    {
        public: 
            static CEntitySystem& GetInstance()
            {
                static CEntitySystem instance;
                return instance;
            }

            CEntitySystem (const CEntitySystem&) = delete;
            CEntitySystem& operator = (const CEntitySystem&) = delete;

        public:
            void Initialize(XMLDocument& document);

            void Destroy(CEntity& entity);
            void CreateBullet(Core::Float2 _Position, Core::Float2 _Size);
            void DestroyAll();
            std::vector<Data::CEntity*> GetByCategory(SEntityCategory::ECategories _Category);

            std::vector<Data::CEntity*> GetAll();
            std::vector<Data::CEntity*> GetAllCollidables();
        private:
            CEntitySystem() {};

        private:
            Core::CIDManager m_IdManager;
            Core::CItemManager<CEntity> m_ItemManager;
    };
}