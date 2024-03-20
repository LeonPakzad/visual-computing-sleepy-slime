#include "data.unloadPhase.h"
#include "data.entitySystem.h"

namespace Data
{
    void CUnloadPhase::OnEnter() {}

    void CUnloadPhase::OnRun()
    {
        CEntitySystem::GetInstance().DestroyAll();
    }

    void CUnloadPhase::OnLeave() {}
}