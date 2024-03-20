#include "game.phase.h"

namespace Game
{
    int CPhase::OnEnter()
    {
        return InternOnEnter();
    }

    int CPhase::OnRun()
    {
        return InternOnRun();
    }

    int CPhase::OnLeave()
    {
        return InternOnLeave();
    }
}
