#pragma once

#include "game.phase.h"

namespace Game 
{
    class CUnloadPhase : public CPhase
    {
        public: 
            static CUnloadPhase& GetInstance()
            {
                static CUnloadPhase instance;
                return instance;
            };
            
            CUnloadPhase(const CUnloadPhase&) = delete;
            CUnloadPhase& operator = (const CUnloadPhase&) = delete;

        private: 
            CUnloadPhase() {};

        private: 
            int InternOnEnter();
            int InternOnRun();
            int InternOnLeave();
    };
}