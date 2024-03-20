#pragma once

#include <tinyxml2.h>

namespace Gfx 
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
            void OnRun(tinyxml2::XMLDocument& _Document);
            void OnLeave();

        private:
            CStartupPhase() {};
    };
}