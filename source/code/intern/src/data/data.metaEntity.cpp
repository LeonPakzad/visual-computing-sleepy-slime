#include "data.metaEntity.h"

namespace Data 
{
    CMetaEntity::CMetaEntity() {}

    CMetaEntity::CMetaEntity(int _ID, std::string _Name, float _Size, Core::AABB2Float _AABB)
        : m_ID(_ID)
        , m_Name(_Name)
        , m_Size(_Size)
        , m_AABB(_AABB)
    {}

    CMetaEntity::~CMetaEntity() {}
}