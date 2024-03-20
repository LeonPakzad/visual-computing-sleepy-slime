#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Gui
{
	class CInput
	{
		public:
			struct SKeyInput
			{
				sf::Keyboard::Key code;
			};

			enum EInputType
			{
				KeyPressed,
				KeyReleased,
				NumberOfInputTypes
			};

			EInputType type;
			SKeyInput key;
	};
}