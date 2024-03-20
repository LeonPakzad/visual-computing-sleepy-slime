#pragma once

#include <queue>

#include "logic.command.h"
#include "../data/data.event.h"

namespace Logic 
{
    class CCommandSystem 
    {
        using CommandQueue = std::queue<CCommand*>;

        public:
            static CCommandSystem& GetInstance()
            {
                static CCommandSystem instance;
                return instance;
            }

            CCommandSystem(const CCommandSystem&) = delete;
            CCommandSystem& operator = (const CCommandSystem&) = delete;

        public:
            CCommand& CreateCommand();
            void AddCommand(CCommand& _Command);
            CCommand& GetNextInQueue();
            void RemoveNextInQueue();
            bool CommandQueueIsEmpty() const;

            static void DispatchInputToLogic(Data::CEvent& _Event);

        private:
            CCommandSystem() {}

        private:
            CommandQueue m_CommandQueue;
    };
}