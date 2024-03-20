#pragma once

#include <tinyxml2.h>

namespace Data 
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

        private: 
            CStartupPhase() {};

        public: 
            void OnEnter();
            void OnRun(tinyxml2::XMLDocument& document);
            void OnLeave();
    };
}