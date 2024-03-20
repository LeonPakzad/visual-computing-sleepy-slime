#pragma once

namespace Gui
{
    class CLoadPhase
    {
        public:
            static CLoadPhase& GetInstance()
            {
                static CLoadPhase instance;
                return instance;
            }

            CLoadPhase(const CLoadPhase&) = delete;
            CLoadPhase& operator = (const CLoadPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CLoadPhase() {};
    };
}