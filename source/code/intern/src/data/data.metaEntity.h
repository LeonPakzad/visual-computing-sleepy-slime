#pragma once

#include <string>

#include "../core/core.aabb.h"

namespace Data 
{
    class CMetaEntity
    {
        public:
            CMetaEntity();
            CMetaEntity(int _ID, std::string _Name, float _Size, Core::AABB2Float _AABB);
            
            ~CMetaEntity();

        public:
            int m_ID;
            std::string m_Name;
            float m_Size;
            Core::AABB2Float m_AABB;

        public:
            static const int g_MaxNumOfTextures = 4;
            void* facets[g_MaxNumOfTextures];
    };
}