#include <string>
#include <SFML/Graphics.hpp>

#include "gfx.loadPhase.h"
#include "core/core.config.h"
#include "game/game.application.h"

namespace Gfx 
{
    void CLoadPhase::Initialize() 
    {
        std::string filePath = Core::Config::screensDir + "load1.jpg";
        m_Texture.loadFromFile(filePath.c_str());
        m_Screen.setTexture(m_Texture);
    }

    void CLoadPhase::Render() 
    {
        Game::CApplication& app = Game::CApplication::GetInstance();

        app.window.clear(sf::Color::Black);
        app.window.draw(m_Screen);
        app.window.display();
    }

    void CLoadPhase::OnEnter() 
    {
        Initialize();
    }

    void CLoadPhase::OnRun() 
    {
        Render();
    }

    void CLoadPhase::OnLeave() {}
}