#pragma once

namespace Data 
{
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

        private: 
            CMainMenuPhase() {};

        public: 
            void OnEnter();
            void OnRun();
            void OnLeave();
    };
}