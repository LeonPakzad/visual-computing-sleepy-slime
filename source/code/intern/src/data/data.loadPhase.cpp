#include <iostream>
#include <tinyxml2.h>

#include "data.loadPhase.h"
#include "data.entitySystem.h"
#include "data.mapSystem.h"

namespace Data 
{
    void CLoadPhase::OnEnter() {}

    void CLoadPhase::OnRun(tinyxml2::XMLDocument& _pDocument) 
    {
        // store all relevant map data in the map system
        Data::CMapSystem::GetInstance().Initialize(_pDocument);

        // we need a entity system that can load entities from xml
        Data::CEntitySystem::GetInstance().Initialize(_pDocument);
    }
    
    void CLoadPhase::OnLeave() {}
}