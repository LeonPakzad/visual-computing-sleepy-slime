#pragma once

namespace Logic 
{
    class CPlayPhase 
    {
        public:
            static CPlayPhase& GetInstance()
            {
                static CPlayPhase instance;
                return instance;
            };
            
            CPlayPhase(const CPlayPhase&) = delete;
            CPlayPhase& operator = (const CPlayPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CPlayPhase() {};

        private:
            static const unsigned int m_TurnsPerSecond = 15;
            const double m_TurnInterval = 1.0 / m_TurnsPerSecond;
            double m_NextTurnTime;
    };
}