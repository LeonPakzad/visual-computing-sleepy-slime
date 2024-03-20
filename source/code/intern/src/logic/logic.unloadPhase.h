#pragma once

namespace Logic 
{
    class CUnloadPhase 
    {
        public:
            static CUnloadPhase& GetInstance()
            {
                static CUnloadPhase instance;
                return instance;
            };

            CUnloadPhase(const CUnloadPhase&) = delete;
            CUnloadPhase& operator = (const CUnloadPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CUnloadPhase() {};
    };
}