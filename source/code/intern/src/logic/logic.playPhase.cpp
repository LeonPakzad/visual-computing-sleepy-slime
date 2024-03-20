#include "logic.playPhase.h"
#include "logic.system.h"
#include "logic.commandSystem.h"

#include "../core/core.time.h"
#include "../data/data.eventSystem.h"

namespace Logic 
{
    void CPlayPhase::OnEnter() 
    {
        Data::CEventSystem::GetInstance().Register(
            Data::SEventType::DispatchInputToCommand, 
            &CCommandSystem::DispatchInputToLogic
        );
    }

    void CPlayPhase::OnRun() 
    {
        if (Core::Time::GetTime() >= m_NextTurnTime)
        {
            m_NextTurnTime += m_TurnInterval;

            CSystem::GetInstance().OnTurn();
        }
    }

    void CPlayPhase::OnLeave() 
    {
        Data::CEventSystem::GetInstance().Unregister(
            Data::SEventType::DispatchInputToCommand, 
            &CCommandSystem::DispatchInputToLogic
        );

        m_NextTurnTime = 0.0;
    }
}