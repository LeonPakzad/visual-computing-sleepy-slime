#include "data.levelSystem.h"

namespace Data
{
    CLevelSystem::CLevelSystem()
        : m_SelectedLevel(1) {}

    int CLevelSystem::GetSelectedLevel() const
    {
        return m_SelectedLevel;
    }

    void CLevelSystem::SetSelectedLevel(int _Level)
    {
        m_SelectedLevel = _Level;
    }

    std::string CLevelSystem::GetSelectedLevelAsString() 
    {
        return std::to_string(m_SelectedLevel);
    }

    std::string CLevelSystem::GetSelectedLevelFileName() 
    {
        return "level-" + GetSelectedLevelAsString() + ".xml";
    }
}