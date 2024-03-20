#pragma once

#include "game.phase.h"
#include <data/data.event.h>

namespace Game
{
    class CPlayPhase : public CPhase
    {
        public:
            static CPlayPhase& GetInstance()
            {
                static CPlayPhase instance;
                return instance;
            };

            CPlayPhase(const CPlayPhase&) = delete;
            CPlayPhase& operator = (const CPlayPhase&) = delete;

            static void PlayerDied(Data::CEvent& event);
            static void Exit(Data::CEvent& event);

        private:
            CPlayPhase();

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;

            CPhase::EType m_NextRunPhase;
    };
}