#include <iostream>

#include "gui.mainMenuPhase.h"
#include "gui.inputSystem.h"

#include "core/core.time.h"
#include "data/data.eventType.h"
#include "data/data.eventSystem.h"

#include <SFML/Window/Keyboard.hpp>

namespace Gui 
{
    CMainMenuPhase::CMainMenuPhase() 
        : m_SelectedMenuLabel(ESelectedMenuLabel::PLAY)
        , m_EnterPressed(false)
        , m_EscapePressed(false)
        , m_IndicateLevelChange(false) 
        , m_IndicateLevelChangeDuration(2)
        , m_SelectedLevel(1)
    {}

    void CMainMenuPhase::OnEnter() {}

    int CMainMenuPhase::OnRun() 
    {
        CInputSystem::GetInstance().OnRun();
        
        return 0;
    }

    void CMainMenuPhase::OnLeave() {}

    int CMainMenuPhase::GetSelectedLevel() const
    {
        return m_SelectedLevel;
    }

    void CMainMenuPhase::SetSelectedLevel(int _Level)
    {
        m_SelectedLevel = _Level;
    }

    bool CMainMenuPhase::IndicateLevelChange()
    {
        bool indicationDurationPassed = this->m_IndicateLevelChangeTimer.getElapsedTime().asSeconds() > m_IndicateLevelChangeDuration;
        if(m_IndicateLevelChange && !indicationDurationPassed)
        {
            return true;
        }

        return false;
    }

    void CMainMenuPhase::SetIndicateLevelChange(bool _IndicateLevelChange)
    {
        this->m_IndicateLevelChange = _IndicateLevelChange;
        this->m_IndicateLevelChangeTimer.restart();
    }

    ESelectedMenuLabel CMainMenuPhase::GetSelectedMenuLabel() 
    {
        return m_SelectedMenuLabel;
    }

    void CMainMenuPhase::SetSelectedMenuLabel(ESelectedMenuLabel _SelectedMenuLabel)
    {
		this->m_SelectedMenuLabel = _SelectedMenuLabel;
	}
}