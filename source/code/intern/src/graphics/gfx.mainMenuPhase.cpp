#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "core/core.config.h"
#include "gfx.mainMenuPhase.h"
#include "game/game.application.h"
#include "gui/gui.mainMenuPhase.h"
#include "data/data.levelSystem.h"

namespace Gfx
{
    void CMainMenuPhase::Initialize() 
    {
        Game::CApplication& app = Game::CApplication::GetInstance();

        std::string filePath;

        // load textures
        filePath = Core::Config::screensDir + "play1.jpg";
        m_Textures[Gui::ESelectedMenuLabel::PLAY].loadFromFile(filePath.c_str());

        filePath = Core::Config::screensDir + "menu-con1.jpg";
        m_Textures[Gui::ESelectedMenuLabel::CONTROLS].loadFromFile(filePath.c_str());
        
        filePath = Core::Config::screensDir + "con1-exit.jpg";
        m_Textures[Gui::ESelectedMenuLabel::CONTROLS_SHOW].loadFromFile(filePath.c_str());

        filePath = Core::Config::screensDir + "exit2.jpg";
        m_Textures[Gui::ESelectedMenuLabel::EXIT].loadFromFile(filePath.c_str());

        // apply textures to sprites
        m_Screens[Gui::ESelectedMenuLabel::PLAY].setTexture(m_Textures[Gui::ESelectedMenuLabel::PLAY]);

        m_Screens[Gui::ESelectedMenuLabel::CONTROLS].setTexture(m_Textures[Gui::ESelectedMenuLabel::CONTROLS]);

        m_Screens[Gui::ESelectedMenuLabel::CONTROLS_SHOW].setTexture(m_Textures[Gui::ESelectedMenuLabel::CONTROLS_SHOW]);

        m_Screens[Gui::ESelectedMenuLabel::EXIT].setTexture(m_Textures[Gui::ESelectedMenuLabel::EXIT]);
    }

    void CMainMenuPhase::Render() 
    {
        Game::CApplication& app = Game::CApplication::GetInstance();
        bool indicateLevelChange = Gui::CMainMenuPhase::GetInstance().IndicateLevelChange();
        if(indicateLevelChange)
        {
            app.window.setView(app.window.getDefaultView());
            app.window.clear(sf::Color(251, 174, 240));

            sf::Font font;
            font.loadFromFile(Core::Config::fontsDir + "Xeliard.ttf");
                                   
            sf::Text text;
            std::string levelText = "Selected Level: " + std::to_string(Data::CLevelSystem::GetInstance().GetSelectedLevel());
            text.setString(levelText);
            text.setFont(font);
            text.setCharacterSize(150);
            text.setFillColor(sf::Color::White);

            sf::Vector2f viewCenter = app.window.getView().getCenter();
            viewCenter.x = viewCenter.x - text.getLocalBounds().width / 2;
            viewCenter.y = viewCenter.y - text.getLocalBounds().height;
            text.setPosition(viewCenter);

            app.window.draw(text);
            app.window.display();
        }
        else
        {
            app.window.setView(app.window.getDefaultView());
            app.window.clear(sf::Color::Black);

            m_Screens[Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel()].setPosition(app.window.getView().getCenter().x / 2, app.window.getView().getCenter().y - m_Screens[Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel()].getGlobalBounds().height / 2);
            
            app.window.draw(m_Screens[Gui::CMainMenuPhase::GetInstance().GetSelectedMenuLabel()]);
            
            app.window.display();
        }
    }

    void CMainMenuPhase::OnEnter() 
    {
        Initialize();
    }

    void CMainMenuPhase::OnRun() 
    {
        Render();
    }

    void CMainMenuPhase::OnLeave() {}
}