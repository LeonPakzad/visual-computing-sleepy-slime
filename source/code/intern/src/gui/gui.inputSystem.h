#pragma once

#include <queue>

#include <SFML/Window/Event.hpp>

#include "data/data.event.h"
#include "gui.input.h"

namespace Gui
{
	class CInputSystem
	{
		using InputQueue = std::queue<CInput*>;

		public:
            static CInputSystem& GetInstance()
            {
                static CInputSystem instance;
                return instance;
            };

            CInputSystem(const CInputSystem&) = delete;
            CInputSystem& operator = (const CInputSystem&) = delete;

            CInput& GetNextInput();
            void RemoveNextInput();
            bool HasInputs() const;

            void OnRun();

            static void DispatchEventToInput(Data::CEvent& _Event);

        private:
            CInputSystem() {};

            InputQueue m_InputQueue;
	};
}