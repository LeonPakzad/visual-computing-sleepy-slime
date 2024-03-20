#pragma once

namespace Game
{
    class CPhase
    {
        public:
            enum EType
            {
                STARTUP,
                MAIN_MENU,
                LOAD_MAP,
                PLAY,
                UNLOAD_MAP,
                SHUTDOWN,
                NumberOfTypes,
                Undefined = -1,
            };

        public:
            int OnEnter();
            int OnRun();
            int OnLeave();

        private:
            virtual int InternOnEnter() = 0;
            virtual int InternOnRun() = 0;
            virtual int InternOnLeave() = 0;
    };
}