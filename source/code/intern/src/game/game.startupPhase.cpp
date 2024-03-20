#include "game.startupPhase.h"

#include <iostream>
#include <string>
#include <tinyxml2.h>

#include "core/core.config.h"
#include "data/data.startupPhase.h"
#include "logic/logic.startupPhase.h"
#include "graphics/gfx.startupPhase.h"
#include "gui/gui.startupPhase.h"


namespace Game 
{
    int CStartupPhase::InternOnEnter() 
    {
        Data::CStartupPhase::GetInstance().OnEnter();
        Logic::CStartupPhase::GetInstance().OnEnter();
        Gfx::CStartupPhase::GetInstance().OnEnter();
        Gui::CStartupPhase::GetInstance().OnEnter();

        return 0;
    }

    int CStartupPhase::InternOnRun() 
    {
        tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
        const std::string filePath = Core::Config::ressourcesDir + "meta-entities.xml";
        document->LoadFile(filePath.c_str());

        Data::CStartupPhase::GetInstance().OnRun(*document);
        Logic::CStartupPhase::GetInstance().OnRun();
        Gfx::CStartupPhase::GetInstance().OnRun(*document);
        Gui::CStartupPhase::GetInstance().OnRun();

        return EType::MAIN_MENU;
    }

    int CStartupPhase::InternOnLeave() 
    {
        Data::CStartupPhase::GetInstance().OnLeave();
        Logic::CStartupPhase::GetInstance().OnLeave();
        Gfx::CStartupPhase::GetInstance().OnLeave();
        Gui::CStartupPhase::GetInstance().OnLeave();
        
        return 0;
    }
}