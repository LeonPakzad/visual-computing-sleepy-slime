#include <tinyxml2.h>

#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"

namespace Data 
{
    void CStartupPhase::OnEnter() {}

    void CStartupPhase::OnRun(tinyxml2::XMLDocument& _pDocument) 
    {
        CMetaEntitySystem::GetInstance().Initialize(_pDocument);
    }
    
    void CStartupPhase::OnLeave() {}
}