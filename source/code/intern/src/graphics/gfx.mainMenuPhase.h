#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "gui/gui.mainMenuPhase.h"

namespace Gfx 
{
    class CMainMenuPhase 
    {
        public: static CMainMenuPhase& GetInstance()
        {
            static CMainMenuPhase instance;
            return instance;
        };
        
        CMainMenuPhase(const CMainMenuPhase&) = delete;
        CMainMenuPhase& operator = (const CMainMenuPhase&) = delete;

        public: 
            void Initialize();
            void Render();

            void OnEnter();
            void OnRun();
            void OnLeave();

        private: 
            CMainMenuPhase() {};

            sf::Texture m_Textures[Gui::ESelectedMenuLabel::Length];
            sf::Sprite m_Screens[Gui::ESelectedMenuLabel::Length];
    };
}