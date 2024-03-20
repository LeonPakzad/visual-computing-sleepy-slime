#pragma once

#include <SFML/System/Clock.hpp>

namespace Gui
{
    enum ESelectedMenuLabel
    {
        PLAY,
        CONTROLS,
        CONTROLS_SHOW,
        EXIT,
        Length
    };

    class CMainMenuPhase
    {
        public:
            static CMainMenuPhase& GetInstance()
            {
                static CMainMenuPhase instance;
                return instance;
            };

            CMainMenuPhase(const CMainMenuPhase&) = delete;
            CMainMenuPhase& operator = (const CMainMenuPhase&) = delete;

        public:
            void OnEnter();
            int OnRun();
            void OnLeave();

            ESelectedMenuLabel GetSelectedMenuLabel();
            void SetSelectedMenuLabel(ESelectedMenuLabel _SelectedMenuLabel);

            int GetSelectedLevel() const;
            void SetSelectedLevel(int _Level);

            bool IndicateLevelChange();
            void SetIndicateLevelChange(bool _IndicateLevelChange);

        private:
            CMainMenuPhase();

            ESelectedMenuLabel m_SelectedMenuLabel;
            bool m_EnterPressed;
            bool m_EscapePressed;

            int m_SelectedLevel;
            bool m_IndicateLevelChange;
            sf::Clock m_IndicateLevelChangeTimer;
            double m_IndicateLevelChangeDuration;
    };
}