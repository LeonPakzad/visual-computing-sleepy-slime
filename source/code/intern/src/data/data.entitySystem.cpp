#include <iostream>
#include <tinyxml2.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "data.entitySystem.h"
#include "data.metaEntitySystem.h"
#include "data.playerSystem.h"
#include "data.enemySystem.h"

#include "../core/core.explode.h"
#include "../core/core.time.h"

namespace Data 
{
    void CEntitySystem::Initialize(tinyxml2::XMLDocument& _pDocument)
    {
        Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* xmlEntities = _pDocument.FirstChildElement("map")->FirstChildElement("entities");
        tinyxml2::XMLElement* xmlEntity = xmlEntities->FirstChildElement("entity");

        while (xmlEntity != nullptr)
        {
            std::string entityName = xmlEntity->FindAttribute("name")->Value();
            std::string metaEntityName = xmlEntity->FindAttribute("meta-entity")->Value();

            auto metaEntityId = metaEntitySystem.GetMetaEntityId(metaEntityName);

            Data::CMetaEntity& metaEntity = metaEntitySystem.GetMetaEntityById(metaEntityId);
            auto type = atoi(
                xmlEntity
                    ->FirstChildElement("data")
                    ->FirstChildElement("type")
                    ->FirstChild()
                    ->Value()
            );
                        
            auto positionFloatStrings = Core::Explode(
                xmlEntity
                ->FirstChildElement("data")
                ->FirstChildElement("position")
                ->FirstChild()
                ->Value(),
                ';'
            );

            auto sizeFloatStrings = Core::Explode(
				xmlEntity
				->FirstChildElement("data")
				->FirstChildElement("size")
				->FirstChild()
				->Value(),
				';'
			);

            Core::CIDManager::BID entityId = m_IdManager.Register(entityName);
            CEntity& entity = m_ItemManager.CreateItem(entityId);
            entity.metaEntity = &metaEntity;
            entity.id = entityId;
            entity.category = type >= SEntityCategory::NumberOfMembers ? SEntityCategory::ECategories::Undefined : SEntityCategory::ECategories(type);
            
            entity.position = Core::Float2(
                std::stof(positionFloatStrings[0]),
                std::stof(positionFloatStrings[1])
            );

            entity.size = Core::Float2(
				std::stof(sizeFloatStrings[0]),
				std::stof(sizeFloatStrings[1])
			);

            entity.aabb = Core::AABB2Float(
				Core::Float2(entity.position[0], entity.position[1]),
                Core::Float2(entity.position[0] + entity.size[0], entity.position[1] + entity.size[1])
			);

            if (entity.category == Data::SEntityCategory::Character)
            {
                Data::CPlayerSystem& playerSystem = Data::CPlayerSystem::GetInstance();
                playerSystem.SetPlayer(&entity);
            }

            if (entity.category == Data::SEntityCategory::Enemy)
            {
                Data::CEnemySystem& enemySystem = Data::CEnemySystem::GetInstance();
                enemySystem.SetEnemy(&entity);
            }

            xmlEntity = xmlEntity->NextSiblingElement("entity");
        }
    }

    void CEntitySystem::Destroy(CEntity& _Entity)
	{
		m_ItemManager.DestroyItem(_Entity.id);
	}

    void CEntitySystem::CreateBullet(Core::Float2 _Position, Core::Float2 _Size)
    {

        Core::Float2 playerPosition = Data::CPlayerSystem::GetInstance().GetPosition();
        
        Core::CVector2<float> direction = Core::Float2(
            playerPosition[0] - _Position[0],
            playerPosition[1] - _Position[1]
        );
        
        Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();

        Core::CIDManager::BID metaEntityId = metaEntitySystem.GetMetaEntityId("bullet");
        Data::CMetaEntity& metaEntity = metaEntitySystem.GetMetaEntityById(metaEntityId);
        int time = floor(Core::Time::GetTime()*100);
        Core::CIDManager::BID entityId = m_IdManager.Register("bullet" + time);

        CEntity& entity = m_ItemManager.CreateItem(entityId);

        entity.metaEntity = &metaEntity;
        entity.id = entityId;
        entity.category = Data::SEntityCategory::Bullet;
        entity.destination = playerPosition;
        entity.direction = Core::Float2(
            playerPosition[0] - _Position[0],
            playerPosition[1] - _Position[1]
        );

        entity.position = Core::Float2(
            _Position[0],
            _Position[1]
        );

        entity.size = Core::Float2(
            _Size[0],
            _Size[1]
        );

        entity.aabb = Core::AABB2Float(
            Core::Float2(
                entity.position[0],
                entity.position[1]),
            Core::Float2(
                entity.position[0] + entity.size[0],
                entity.position[1] + entity.size[1]
            )
        );
    }

    void CEntitySystem::DestroyAll()
	{
        m_ItemManager.Clear();
        m_IdManager.Clear();
	}

    std::vector<Data::CEntity*> CEntitySystem::GetAll()
    {
        return m_ItemManager.GetAll();
    }

    std::vector<Data::CEntity*> CEntitySystem::GetByCategory(SEntityCategory::ECategories _Category)
    {
        std::vector<Data::CEntity*> entities;
        m_ItemManager.GetAll();

        for (auto& entity : m_ItemManager.GetAll())
        {
            if (entity == nullptr)
            {
                continue;
            }

            if (entity->category == _Category)
            {
                entities.push_back(entity);
            }
        }

        return entities;
    }

    std::vector<Data::CEntity*> CEntitySystem::GetAllCollidables()
    {
		std::vector<Data::CEntity*> collidables;
        std::vector<std::string> collidableNames = { 
            "wall-top",
            "wall-bottom",
            "wall-left",
            "wall-right",
            "wall-corner-top-left",
            "wall-corner-top-left-inverted",
            "wall-corner-bottom-left",
            "wall-corner-bottom-left-inverted",
            "wall-corner-top-right",
            "wall-corner-top-right-inverted",
            "wall-corner-bottom-right",
            "wall-corner-bottom-right-inverted",
            "player",
            "bush",
            "wood-small",
            "wood-big",
            "rock-small",
            "rock-medium",
            "rock-big",
            "wizard-red",
            "wizard-blue",
            "bullet",
        };

        for (auto& entity : m_ItemManager.GetAll())
        {
            if (entity == nullptr)
            {
                continue;
            }

            if (std::find(collidableNames.begin(), collidableNames.end(), entity->metaEntity->m_Name) != collidableNames.end())
            {
				collidables.push_back(entity);
			}
		}

		return collidables;
	}
}