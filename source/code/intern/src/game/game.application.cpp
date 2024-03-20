#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <exception>

#include "game.application.h"
#include "game.phase.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

#include "data/data.eventSystem.h"
#include "logic/logic.commandSystem.h"



namespace Game 
{
    CApplication::CApplication()
        : currentPhaseIndex(CPhase::Undefined)
    {
        phases[CPhase::STARTUP] = &CStartupPhase::GetInstance(); 
        phases[CPhase::MAIN_MENU] = &CMainMenuPhase::GetInstance();
        phases[CPhase::LOAD_MAP] = &CLoadPhase::GetInstance();
        phases[CPhase::PLAY] = &CPlayPhase::GetInstance();
        phases[CPhase::UNLOAD_MAP] = &CUnloadPhase::GetInstance();
        phases[CPhase::SHUTDOWN] = &CShutdownPhase::GetInstance();
    }

    void CApplication::Startup()
    {
        window.create(sf::VideoMode(0, 0), "Slime Survival - Visual Computing - Leon Pakzad", sf::Style::Fullscreen);
        window.setFramerateLimit(30);

        currentPhaseIndex = CPhase::STARTUP;
        CPhase* currentPhase = phases[currentPhaseIndex];
        assert(currentPhase != nullptr);
        currentPhase->OnEnter();
    }

    void CApplication::Run()
    {
        std::unordered_map<int, bool> pressedKeys;
        
        for (;;) 
        {
            if (window.isOpen() == false) 
            {
                break;
            }

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && pressedKeys.count(event.key.code) == 0)
				{
					pressedKeys[event.key.code] = true;
				}

                if (event.type == sf::Event::KeyReleased && pressedKeys.count(event.key.code) == 1)
                {
                    pressedKeys.erase(event.key.code);
                }
            }

            for (auto& key : pressedKeys)
            {
                Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchEventToInput, key.first);
            }

            if (HandlePhaseChange() == GAME_LIFECYCLE_ENDED)
            {
                break;
            }
        }
    }

    void CApplication::Shutdown() {}

    EHandlePhaseChangeResult CApplication::HandlePhaseChange()
    {
        CPhase* currentPhase = phases[currentPhaseIndex];
        assert(currentPhase != nullptr);
        
        int nextPhaseIndex = currentPhase->OnRun();
        if (nextPhaseIndex != currentPhaseIndex) 
        {
            currentPhase->OnLeave();

            if (currentPhaseIndex == CPhase::SHUTDOWN) 
            {
                return GAME_LIFECYCLE_ENDED;
            }

            currentPhaseIndex = nextPhaseIndex;
            currentPhase = phases[currentPhaseIndex];

            assert(currentPhase != nullptr);
            currentPhase->OnEnter();

            return PHASE_CHANGED;
        }

        return PHASE_REMAINS;
    }
}

int main()
{
    Game::CApplication& app = Game::CApplication::GetInstance();

    try
    {
        app.Startup();
        app.Run();
    }
    catch (const std::exception& _pException)
    {
		std::cerr << _pException.what() << std::endl;
	}
    catch (...)
    {
		std::cerr << "Unknown exception occured" << std::endl;
	}

    try
    {
        app.Shutdown();
    }
    catch (const std::exception& _pException)
    {
        std::cerr << _pException.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occured" << std::endl;
	}
    
    return 0;
}