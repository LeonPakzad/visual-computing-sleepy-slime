#pragma once
#include <iostream>

#include "game.phase.h"
#include <SFML/Graphics/RenderWindow.hpp>

enum EHandlePhaseChangeResult
{
    PHASE_REMAINS,
    PHASE_CHANGED,
    GAME_LIFECYCLE_ENDED
};

namespace Game
{
    class CApplication
    {
        public:
            static CApplication& GetInstance()
            {
                static CApplication instance;
                return instance;
            };

            CApplication(const CApplication&) = delete;
            CApplication& operator = (const CApplication&) = delete;

        private:
            CApplication();
            int currentPhaseIndex;
            CPhase* phases [CPhase::NumberOfTypes];

        public:
            sf::RenderWindow window;

        public:
            void Startup();
            void Run();
            void Shutdown();

        private:
            EHandlePhaseChangeResult HandlePhaseChange();
    };
}