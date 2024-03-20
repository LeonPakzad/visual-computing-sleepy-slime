#pragma once
#include "game.phase.h"

namespace Game
{
    class CLoadPhase : public CPhase
    {
        public:
            static CLoadPhase& GetInstance()
            {
                static CLoadPhase instance;
                return instance;
            };

            CLoadPhase(const CLoadPhase&) = delete;
            CLoadPhase& operator = (const CLoadPhase&) = delete;

        private:
            CLoadPhase() {};

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;
    };
}