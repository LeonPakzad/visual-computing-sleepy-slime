#pragma once

#include "game.phase.h"
#include <data/data.event.h>

namespace Game
{
    class CMainMenuPhase : public CPhase
    {
        public:
            static CMainMenuPhase& GetInstance()
            {
                static CMainMenuPhase instance;
                return instance;
            };

            CMainMenuPhase(CMainMenuPhase const&) = delete;
            CMainMenuPhase& operator=(CMainMenuPhase const&) = delete;

        // event callbacks
        public:
            static void OnStart(Data::CEvent& event);
            static void OnEnter(Data::CEvent& event);
            static void OnUp(Data::CEvent& event);
            static void OnDown(Data::CEvent& event);
            static void OnExit(Data::CEvent& event);
            static void OnOne(Data::CEvent& event);
            static void OnTwo(Data::CEvent& event);

        private:
            CMainMenuPhase() {};

            CPhase::EType m_NextRunPhase;
            static void SetLevel(int level);

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;
    };
}