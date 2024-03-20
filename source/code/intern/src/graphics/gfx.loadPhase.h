#pragma once

#include <SFML/Graphics.hpp>

namespace Gfx
{
    class CLoadPhase 
    {
        public:
            static CLoadPhase& GetInstance()
            {
                static CLoadPhase instance;
                return instance;
            };
            
            CLoadPhase(const CLoadPhase&) = delete;
            CLoadPhase& operator = (const CLoadPhase&) = delete;

        public:
            void Initialize();
            void Render();

            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CLoadPhase() {};

            sf::Texture m_Texture;
            sf::Sprite m_Screen;
    };
}