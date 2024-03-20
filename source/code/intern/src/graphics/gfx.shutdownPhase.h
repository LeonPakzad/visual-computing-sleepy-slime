#pragma once

namespace Gfx
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

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CShutdownPhase() {};
    };
}