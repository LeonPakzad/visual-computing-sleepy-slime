#pragma once

namespace Data 
{
    class CShutdownPhase
    {
        public: 
            static CShutdownPhase& GetInstance()
            {
                static CShutdownPhase instance;
                return instance;
            };
            
            CShutdownPhase(const CShutdownPhase&) = delete;
            CShutdownPhase& operator = (const CShutdownPhase&) = delete;

        private: 
            CShutdownPhase() {};

        public: 
            void OnEnter();
            void OnRun();
            void OnLeave();
    };
}