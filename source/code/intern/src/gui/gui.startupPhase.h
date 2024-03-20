#pragma once

namespace Gui
{
    class CStartupPhase
    {
        public:
            static CStartupPhase& GetInstance()
            {
                static CStartupPhase instance;
                return instance;
            };

            CStartupPhase(const CStartupPhase&) = delete;
            CStartupPhase& operator = (const CStartupPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            CStartupPhase() {};
    };
}