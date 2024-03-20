#pragma once

namespace Data
{
	struct SCommandAction
	{
		enum EActions
		{
			MoveRight,
			MoveLeft,
			MoveUp,
			MoveDown,
			NumberOfActions,
			Undefined = -1
		};
	};
}