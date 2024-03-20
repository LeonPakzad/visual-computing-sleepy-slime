#pragma once

#include "data.entityCategory.h"
#include "data.entityFolder.h"

namespace Data
{
    class CSector
    {
        private:
            int           m_PositionX;
            int           m_PositionY;
            CEntityFolder  m_Folders[SEntityCategory::NumberOfMembers];
    };
}
