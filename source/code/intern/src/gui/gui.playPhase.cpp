#include "gui.playPhase.h"
#include "gui.inputSystem.h"

namespace Gui 
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        CInputSystem::GetInstance().OnRun();
    }
    
    void CPlayPhase::OnLeave() {}
}