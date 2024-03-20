#include "gui.shutdownPhase.h"
#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"

namespace Gui 
{
    void CShutdownPhase::OnEnter() {}

    void CShutdownPhase::OnRun() {}

    void CShutdownPhase::OnLeave() 
    {
        Data::CEventSystem::GetInstance().Unregister(
            Data::SEventType::DispatchEventToInput,  
            &CInputSystem::GetInstance().DispatchEventToInput
        );
    }
}