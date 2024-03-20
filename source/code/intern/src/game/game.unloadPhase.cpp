#include "game.unloadPhase.h"

#include <iostream>

#include "logic/logic.unloadPhase.h"
#include "graphics/gfx.unloadPhase.h"
#include "gui/gui.unloadPhase.h"
#include "data/data.unloadPhase.h"

namespace Game 
{
    int CUnloadPhase::InternOnEnter() 
    {
        Logic::CUnloadPhase::GetInstance().OnEnter();
        Gfx::CUnloadPhase::GetInstance().OnEnter();
        Gui::CUnloadPhase::GetInstance().OnEnter();
        Data::CUnloadPhase::GetInstance().OnEnter();

        return 0;
    }

    int CUnloadPhase::InternOnRun() 
    {
        Logic::CUnloadPhase::GetInstance().OnRun();
        Gfx::CUnloadPhase::GetInstance().OnRun();
        Gui::CUnloadPhase::GetInstance().OnRun();
        Data::CUnloadPhase::GetInstance().OnRun();

        return EType::MAIN_MENU;
    }

    int CUnloadPhase::InternOnLeave() 
    {
        Logic::CUnloadPhase::GetInstance().OnLeave();
        Gfx::CUnloadPhase::GetInstance().OnLeave();
        Gui::CUnloadPhase::GetInstance().OnLeave();
        Data::CUnloadPhase::GetInstance().OnLeave();

        return 0;
    }
}