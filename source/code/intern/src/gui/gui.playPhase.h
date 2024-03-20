#pragma once

namespace Gui
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
    };
}