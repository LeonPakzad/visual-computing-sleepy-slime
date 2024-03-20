#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "data/data.eventSystem.h"
#include "data/data.levelSystem.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"
#include <SFML/System/Sleep.hpp>

namespace Game 
{
    int CMainMenuPhase::InternOnEnter() 
    {
        m_NextRunPhase = EType::MAIN_MENU;

        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedEnter, &CMainMenuPhase::OnEnter);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedEscape, &CMainMenuPhase::OnExit);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedUp, &CMainMenuPhase::OnUp);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedDown, &CMainMenuPhase::OnDown);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedOne, &CMainMenuPhase::OnOne);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedTwo, &CMainMenuPhase::OnTwo);

        Data::CMainMenuPhase::GetInstance().OnEnter();
        Gfx::CMainMenuPhase::GetInstance().OnEnter();
        Gui::CMainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int CMainMenuPhase::InternOnRun() 
    {
        Data::CMainMenuPhase::GetInstance().OnRun();
        Gfx::CMainMenuPhase::GetInstance().OnRun();
        Gui::CMainMenuPhase::GetInstance().OnRun();

        return m_NextRunPhase;
    }

    int CMainMenuPhase::InternOnLeave() 
    {
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedEnter, &CMainMenuPhase::OnEnter);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedEscape, &CMainMenuPhase::OnExit);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedUp, &CMainMenuPhase::OnUp);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedDown, &CMainMenuPhase::OnDown);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedOne, &CMainMenuPhase::OnOne);
		Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedTwo, &CMainMenuPhase::OnTwo);

        Data::CMainMenuPhase::GetInstance().OnLeave();
        Gfx::CMainMenuPhase::GetInstance().OnLeave();
        Gui::CMainMenuPhase::GetInstance().OnLeave();

        return 0;
    }

    void CMainMenuPhase::OnStart(Data::CEvent&)
    {
        CMainMenuPhase::GetInstance().m_NextRunPhase = CPhase::LOAD_MAP;
    }

    void CMainMenuPhase::OnEnter(Data::CEvent&)
    {
        Gui::ESelectedMenuLabel selectedLabel = Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel();
        
        if(selectedLabel == Gui::ESelectedMenuLabel::PLAY) 
        {
            CMainMenuPhase::GetInstance().m_NextRunPhase = CPhase::LOAD_MAP;
        }
        else if (selectedLabel == Gui::ESelectedMenuLabel::EXIT)
        {
			CMainMenuPhase::GetInstance().m_NextRunPhase = CPhase::SHUTDOWN;
		}
        else if (selectedLabel == Gui::ESelectedMenuLabel::CONTROLS_SHOW)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::CONTROLS);
            sf::sleep(sf::seconds(0.2f));
        }
        else if (selectedLabel == Gui::ESelectedMenuLabel::CONTROLS)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::CONTROLS_SHOW);
            sf::sleep(sf::seconds(0.2f));
        }
	}

    void CMainMenuPhase::OnUp(Data::CEvent&)
    {
        if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::PLAY)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::EXIT);
        }
        else if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::CONTROLS)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::PLAY);
        }
        else if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::EXIT)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::CONTROLS);
        }
        sf::sleep(sf::seconds(0.2f));
	}

    void CMainMenuPhase::OnDown(Data::CEvent&)
    {
        if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::PLAY)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::CONTROLS);
        }
        else if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::CONTROLS)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::EXIT);
        }
        else if (Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel() == Gui::ESelectedMenuLabel::EXIT)
        {
            Gui::CMainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::ESelectedMenuLabel::PLAY);
        }
        sf::sleep(sf::seconds(0.2f));
    }

    void CMainMenuPhase::OnExit(Data::CEvent&)
    {
        if (CMainMenuPhase::GetInstance().m_NextRunPhase == CPhase::PLAY)
        {
            CMainMenuPhase::GetInstance().m_NextRunPhase = CPhase::MAIN_MENU;
        }
        else
        {
            CMainMenuPhase::GetInstance().m_NextRunPhase = CPhase::SHUTDOWN;
        }
    }

    void CMainMenuPhase::SetLevel(int _Level)
    {
        Data::CLevelSystem::GetInstance().SetSelectedLevel(_Level);
        Gui::CMainMenuPhase::GetInstance().SetIndicateLevelChange(true);
    }

    void CMainMenuPhase::OnOne(Data::CEvent&)
    {
        SetLevel(1);
    }

    void CMainMenuPhase::OnTwo(Data::CEvent&)
    {
        SetLevel(2);
    }
}