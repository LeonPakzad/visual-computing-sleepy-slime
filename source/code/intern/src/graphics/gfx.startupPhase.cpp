#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx.startupPhase.h"
#include "core/core.config.h"
#include "data/data.metaEntitySystem.h"

namespace Gfx
{
    void CStartupPhase::OnEnter() {}

    void CStartupPhase::OnRun(tinyxml2::XMLDocument& _pDocument) 
    {
        Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* xmlMetaEntities = _pDocument.FirstChildElement("meta-entities");
        tinyxml2::XMLElement* xmlMetaEntity = xmlMetaEntities->FirstChildElement("meta-entity");

        while(xmlMetaEntity != nullptr) 
        {
            auto metaEntityId = metaEntitySystem.GetMetaEntityId(
                xmlMetaEntity
                    ->FindAttribute("name")
                    ->Value()
            );
            Data::CMetaEntity& metaEntity = metaEntitySystem.GetMetaEntityById(metaEntityId);
            
            //use once multiple forms of graphics are needed
            tinyxml2::XMLElement* xmlGraphicsElement = xmlMetaEntity->FirstChildElement("graphics");
            
            tinyxml2::XMLElement* xmlTextureElement = xmlGraphicsElement->FirstChildElement("texture");
            for(int Index = 0; xmlTextureElement != nullptr; Index++)
            {
                std::string textureName = xmlTextureElement->FindAttribute("value")->Value();
                std::string filePath = (Core::Config::texturesDir + textureName).c_str();
                sf::Texture* texture = new sf::Texture();
            
                if(texture->loadFromFile(filePath)) 
                {
                    metaEntity.facets[Index] = texture;
                }
                xmlTextureElement = xmlTextureElement->NextSiblingElement("texture");
            }
            
            xmlMetaEntity = xmlMetaEntity->NextSiblingElement("meta-entity");
        }
    }

    void CStartupPhase::OnLeave() {}
}