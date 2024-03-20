
#include <iostream>

#include "data.playerSystem.h"
#include "data.enemySystem.h"

#include "../core/core.time.h"

namespace Data 
{
    CEntity* CPlayerSystem::GetPlayer()
    {
        return m_Player;
    }

    void CPlayerSystem::SetPlayer(CEntity* _pPlayer)
    {
        this->m_Player = _pPlayer;
    }

    void CPlayerSystem::SetDirection(EViewDirection _Direction)
    {
        this->m_Direction = _Direction;
    }

    Data::CPlayerSystem::EViewDirection CPlayerSystem::GetDirection()
    {
        return this->m_Direction;
    }

    Core::Float2 CPlayerSystem::GetPosition()
    {
        return this->m_Player->position;
    }

    void CPlayerSystem::MovePlayer(Core::Float2 _Distance)
    {
        this->m_Player->position = Core::Float2(
            this->m_Player->position[0] + _Distance[0],
            this->m_Player->position[1] + _Distance[1]
        );
        this->m_Player->aabb = Core::CAABB2<float>(
            Core::Float2(
                this->m_Player->position[0],
                this->m_Player->position[1]
            ),
            Core::Float2(
                this->m_Player->position[0] + this->m_Player->size[0],
                this->m_Player->position[1] + this->m_Player->size[1]
            )
        );
    }

    void CPlayerSystem::Die()
    {
		this->m_IsDead = true;
		this->m_DiedAt = Core::Time::GetTime();
        CEnemySystem::GetInstance().SetLastAttack(0);
	}

    void CPlayerSystem::Revive()
    {
        CEnemySystem::GetInstance().SetLastAttack(0);
        this->m_IsDead = false;
        this->m_DiedAt = 0.0;
    }

    bool CPlayerSystem::DeadSequenceIsOver()
    {
		return Core::Time::GetTime() - this->m_DiedAt > this->m_ShowDeadMessageFor;
	}

    bool CPlayerSystem::IsDead()
    {
		return this->m_IsDead;
	}
    double CPlayerSystem::GetDiedAt()
    {
        return this->m_DiedAt;
    }
}