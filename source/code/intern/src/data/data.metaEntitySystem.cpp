#include <iostream>

#include "data.metaEntitySystem.h"

#include "../core/core.explode.h"
#include "../core/core.aabb.h"

namespace Data
{
    int CMetaEntitySystem::Initialize(tinyxml2::XMLDocument& _pDocument)
    {
        int metaEntityCount = 0;

        tinyxml2::XMLElement* metaEntities = _pDocument.FirstChildElement("meta-entities");
        tinyxml2::XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");

        while (metaEntity != nullptr)
        {
            std::string name = metaEntity->Attribute("name");

            tinyxml2::XMLElement* dataElement = metaEntity->FirstChildElement("data");

            float size = dataElement->FirstChildElement("size")->FloatAttribute("value");

            auto minCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->Attribute("minCorner"), ';');
            auto maxCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->Attribute("maxCorner"), ';');
            
            Core::AABB2Float aabb = Core::AABB2Float(
                Core::Float2(
                    std::stof(minCornerStrings[0]),
                    std::stof(minCornerStrings[1])
                ),
                Core::Float2(
                    std::stof(maxCornerStrings[0]),
                    std::stof(maxCornerStrings[1])
                )
            );

            CMetaEntity& entity = m_ItemManager.CreateItem(m_IDManager.Register(name));
            entity.m_Name = name;
            entity.m_Size = size;
            entity.m_AABB = aabb;

            metaEntityCount++;

            metaEntity = metaEntity->NextSiblingElement("meta-entity");
        }

        return metaEntityCount;
    }

    Core::CIDManager::BID CMetaEntitySystem::GetMetaEntityId(std::string _Name) 
    {
        return m_IDManager.GetByName(_Name);
    }

    CMetaEntity& CMetaEntitySystem::GetMetaEntityById(Core::CIDManager::BID _ID) 
    {
        return m_ItemManager.GetItem(_ID);
    }
}