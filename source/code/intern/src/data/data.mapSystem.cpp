#include "data.mapSystem.h"

#include <iostream>
#include <string>

namespace Data 
{
    CMapSystem::CMapSystem()
        : m_Height(0.0f)
        , m_Width(0.0f)
    {}

    float CMapSystem::GetHeight()
    {
		return this->m_Height;
	}

    float CMapSystem::GetWidth()
    {
        return this->m_Width;
    }

    float CMapSystem::GetMapStartX()
    {
        return 0.0f;
    }

    float CMapSystem::GetMapStartY()
    {
        return 0.0f;
    }

    float CMapSystem::GetMapEndX()
    {
        return this->m_Width;
    }

    float CMapSystem::GetMapEndY()
    {
        return 0.0f;
    }

    float CMapSystem::GetViewBorderXStart()
    {
		return 0.0f;
	}

    float CMapSystem::GetViewBorderXEnd()
    {
        return this->m_Width;
    }

    float CMapSystem::GetViewBorderYStart()
    {
        return 0.0f;
    }

    float CMapSystem::GetViewBorderYEnd()
    {
        return this->m_Height;
    }

    void CMapSystem::Initialize(tinyxml2::XMLDocument& _pDocument)
    {
        tinyxml2::XMLElement* xmlMap = _pDocument.RootElement();

        this->m_Height = std::stof(xmlMap->FirstChildElement("height")->GetText());
        this->m_Width = std::stof(xmlMap->FirstChildElement("width")->GetText());
    }
}