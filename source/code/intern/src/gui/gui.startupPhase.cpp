#include "gui.startupPhase.h"
#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"


namespace Gui 
{
    void CStartupPhase::OnEnter() 
    {
        Data::CEventSystem::GetInstance().Register(
            Data::SEventType::DispatchEventToInput,  
            &CInputSystem::GetInstance().DispatchEventToInput
        );
    }

    void CStartupPhase::OnRun() {}
    
    void CStartupPhase::OnLeave() {}
}