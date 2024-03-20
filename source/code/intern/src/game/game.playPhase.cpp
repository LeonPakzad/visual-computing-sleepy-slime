#include "game.playPhase.h"

#include <iostream>

#include "core/core.time.h"
#include "game/game.application.h"
#include "data/data.eventSystem.h"
#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

namespace Game 
{
    CPlayPhase::CPlayPhase() 
        : m_NextRunPhase(EType::PLAY) {}

    int CPlayPhase::InternOnEnter() 
    {   
        m_NextRunPhase = EType::PLAY;

        Core::Time::Reset();

        Data::CEventSystem::GetInstance().Register(Data::SEventType::PlayerDied, &CPlayPhase::PlayerDied);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::PressedEscape, &CPlayPhase::Exit);

        Gfx::CPlayPhase::GetInstance().OnEnter();
        Gui::CPlayPhase::GetInstance().OnEnter();
        Logic::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnRun() 
    {
        Core::Time::OnFrame();

        Gfx::CPlayPhase::GetInstance().OnRun();
        Gui::CPlayPhase::GetInstance().OnRun();
        Logic::CPlayPhase::GetInstance().OnRun();

        return m_NextRunPhase;
    }

    int CPlayPhase::InternOnLeave() 
    {
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PlayerDied, &CPlayPhase::PlayerDied);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::PressedEscape, &CPlayPhase::Exit);

        Gfx::CPlayPhase::GetInstance().OnLeave();
        Gui::CPlayPhase::GetInstance().OnLeave();
        Logic::CPlayPhase::GetInstance().OnLeave();

        return 0;
    }

    void CPlayPhase::PlayerDied(Data::CEvent&)
    {
        CPlayPhase::GetInstance().m_NextRunPhase = EType::UNLOAD_MAP;
    }

    void CPlayPhase::Exit(Data::CEvent&)
    {
        CPlayPhase::GetInstance().m_NextRunPhase = EType::UNLOAD_MAP;
    }
}