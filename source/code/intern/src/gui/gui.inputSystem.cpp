#include <iostream>
#include <assert.h>

#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"
#include "data/data.commandAction.h"

namespace Gui
{
	void CInputSystem::DispatchEventToInput(Data::CEvent& _Event)
	{
		CInput& input = *(new CInput());

		input.key.code = sf::Keyboard::Key(_Event.GetData());

		CInputSystem::GetInstance().m_InputQueue.push(&input);
	}

    CInput& CInputSystem::GetNextInput()
    {
        assert(!m_InputQueue.empty());

        return *m_InputQueue.front();
    }

    void CInputSystem::RemoveNextInput()
    {
        assert(!m_InputQueue.empty());

        CInput* input = m_InputQueue.front();

        delete input;

        m_InputQueue.pop();
    }

    bool CInputSystem::HasInputs() const
    {
        return !m_InputQueue.empty();
    }

    void CInputSystem::OnRun()
    {
        CInput current;

        while (HasInputs())
        {
            current = GetNextInput();

            switch (current.key.code)
            {
                case sf::Keyboard::Key::W:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedUp);

                    Data::CEventSystem::GetInstance().FireEvent(
                        Data::SEventType::DispatchInputToCommand,
                        Data::SCommandAction::MoveUp
                    );
                    break;
                
                case sf::Keyboard::Key::S:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedDown);

                    Data::CEventSystem::GetInstance().FireEvent(
                        Data::SEventType::DispatchInputToCommand,
                        Data::SCommandAction::MoveDown
                    );
                    break;

                case sf::Keyboard::Key::A:
                    Data::CEventSystem::GetInstance().FireEvent(
                        Data::SEventType::DispatchInputToCommand,
                        Data::SCommandAction::MoveLeft
                    );
                    break;

                case sf::Keyboard::Key::D:
                    Data::CEventSystem::GetInstance().FireEvent(
                        Data::SEventType::DispatchInputToCommand,
                        Data::SCommandAction::MoveRight
                    );
                    break;

                case sf::Keyboard::Key::Space:
                    Data::CEventSystem::GetInstance().FireEvent(
                        Data::SEventType::DispatchInputToCommand,
                        Data::SCommandAction::MoveUp
                    );
                    break;

                case sf::Keyboard::Num1:
                case sf::Keyboard::Numpad1:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedOne);
                    break;

                case sf::Keyboard::Num2:
                case sf::Keyboard::Numpad2:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedTwo);
                    break;

                case sf::Keyboard::Key::Escape:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedEscape);
                    break;

                case sf::Keyboard::Key::Enter:
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PressedEnter);
                    break;
            }

            RemoveNextInput();
        }
    }
}