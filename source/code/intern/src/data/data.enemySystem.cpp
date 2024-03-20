
#include <iostream>

#include "data.enemySystem.h"
#include "data.metaEntitySystem.h"

#include "../core/core.time.h"
#include "data.entitySystem.h"
#include "data.playerSystem.h"

namespace Data
{
    CEntity* CEnemySystem::GetEnemy()
    {
        return m_Enemy;
    }

    void CEnemySystem::SetEnemy(CEntity* _pEnemy)
    {
        this->m_Enemy = _pEnemy;
    }

    double CEnemySystem::GetLastAttack()
    {
        return this->m_lastAttack;
    }

    void CEnemySystem::SetLastAttack(double _time)
    {
        this->m_lastAttack = _time;
    }

    void CEnemySystem::SetDirection(EViewDirection _Direction)
    {
        this->m_Direction = _Direction;
    }

    Data::CEnemySystem::EViewDirection CEnemySystem::GetDirection()
    {
        return this->m_Direction;
    }

    void CEnemySystem::MoveEnemy(Core::Float2 _Distance)
    {
        this->m_Enemy->position = Core::Float2(
            this->m_Enemy->position[0] + _Distance[0],
            this->m_Enemy->position[1] + _Distance[1]
        );
        this->m_Enemy->aabb = Core::CAABB2<float>(
            Core::Float2(
                this->m_Enemy->position[0],
                this->m_Enemy->position[1]
            ),
            Core::Float2(
                this->m_Enemy->position[0] + this->m_Enemy->size[0],
                this->m_Enemy->position[1] + this->m_Enemy->size[1]
            )
        );
    }

    void CEnemySystem::Attack()
    {
        Core::Float2 playerPosition = Data::CPlayerSystem::GetInstance().GetPosition();
        Core::Float2 enemyPosition = this->GetEnemy()->position;

        Core::CVector2<float> direction = Core::Float2(
            playerPosition[0] - enemyPosition[0],
            playerPosition[1] - enemyPosition[1]
        );

        Core::CVector2<float> bulletSize = Core::Float2(16,16);

        CEntitySystem::GetInstance().CreateBullet(this->GetEnemy()->position, bulletSize);
        
        this->m_lastAttack = Core::Time::GetTime();
    }
}