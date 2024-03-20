#include "game.shutdownPhase.h"

#include <iostream>

#include "game.application.h"

#include "data/data.shutdownPhase.h"
#include "logic/logic.shutdownPhase.h"
#include "graphics/gfx.shutdownPhase.h"
#include "gui/gui.shutdownPhase.h"

namespace Game 
{
    int CShutdownPhase::InternOnEnter()
    {
        Data::CShutdownPhase::GetInstance().OnEnter();
        Logic::CShutdownPhase::GetInstance().OnEnter();
        Gfx::CShutdownPhase::GetInstance().OnEnter();
        Gui::CShutdownPhase::GetInstance().OnEnter();

        return 0;
    }

    int CShutdownPhase::InternOnRun()
    {
        Data::CShutdownPhase::GetInstance().OnRun();
        Logic::CShutdownPhase::GetInstance().OnRun();
        Gfx::CShutdownPhase::GetInstance().OnRun();
        Gui::CShutdownPhase::GetInstance().OnRun();

        return EType::Undefined;
    }

    int CShutdownPhase::InternOnLeave()
    {
        Data::CShutdownPhase::GetInstance().OnLeave();
        Logic::CShutdownPhase::GetInstance().OnLeave();
        Gfx::CShutdownPhase::GetInstance().OnLeave();
        Gui::CShutdownPhase::GetInstance().OnLeave();

        CApplication::GetInstance().window.close();

        return 0;
    }
}