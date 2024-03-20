#pragma once

namespace Data
{
    struct SEventType
    {
        enum EEvents
        {
            PlayerDied,

            DispatchEventToInput,
            DispatchInputToCommand,

            PressedEscape,
            PressedEnter,
            PressedUp,
            PressedDown,
            PressedOne,
            PressedTwo,

            NumberOfEventTypes,
            Undefined = -1
        };
    };
}