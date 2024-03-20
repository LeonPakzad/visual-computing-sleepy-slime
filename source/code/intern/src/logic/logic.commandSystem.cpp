#include "logic.commandSystem.h"

#include <assert.h>

namespace Logic 
{
    CCommand& CCommandSystem::CreateCommand() 
    {
        return *(new CCommand());
    }

    void CCommandSystem::AddCommand(CCommand& _Command) 
    {
        m_CommandQueue.push(&_Command);
    }

    CCommand& CCommandSystem::GetNextInQueue() 
    {
        assert(!m_CommandQueue.empty());

        return *m_CommandQueue.front();
    }

    void CCommandSystem::RemoveNextInQueue() 
    {
        CCommand* command = m_CommandQueue.front();
        delete command;
        m_CommandQueue.pop();
    }

    bool CCommandSystem::CommandQueueIsEmpty() const 
    {
        return m_CommandQueue.empty();
    }

    void CCommandSystem::DispatchInputToLogic(Data::CEvent& _Event)
    {
        CCommand& command = *(new CCommand());

        command.SetType(Data::SCommandAction::EActions(_Event.GetData()));

        CCommandSystem::GetInstance().AddCommand(command);
	}
}