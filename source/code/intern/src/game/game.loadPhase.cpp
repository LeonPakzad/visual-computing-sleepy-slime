#include "game.loadPhase.h"

#include <iostream>
#include <string>
#include <tinyxml2.h>

#include "core/core.config.h"
#include "data/data.loadPhase.h"
#include "data/data.levelSystem.h"
#include "logic/logic.loadPhase.h"
#include "graphics/gfx.loadPhase.h"
#include "gui/gui.loadPhase.h"

using namespace tinyxml2;

namespace Game 
{
    int CLoadPhase::InternOnEnter() 
    {
        Data::CLoadPhase::GetInstance().OnEnter();
        Logic::CLoadPhase::GetInstance().OnEnter();
        Gfx::CLoadPhase::GetInstance().OnEnter();
        Gui::CLoadPhase::GetInstance().OnEnter();

        return 0;
    }

    int CLoadPhase::InternOnRun() 
    {
        XMLDocument* document = new XMLDocument();
        std::string filePath = Core::Config::levelsDir + Data::CLevelSystem::GetInstance().GetSelectedLevelFileName();
        document->LoadFile(filePath.c_str());

        Data::CLoadPhase::GetInstance().OnRun(*document);
        Logic::CLoadPhase::GetInstance().OnRun();
        Gfx::CLoadPhase::GetInstance().OnRun();
        Gui::CLoadPhase::GetInstance().OnRun();

        return EType::PLAY;
    }

    int CLoadPhase::InternOnLeave() 
    {
        Data::CLoadPhase::GetInstance().OnLeave();
        Logic::CLoadPhase::GetInstance().OnLeave();
        Gfx::CLoadPhase::GetInstance().OnLeave();
        Gui::CLoadPhase::GetInstance().OnLeave();

        return 0;
    }
}