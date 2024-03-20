#pragma once

#include "../core/core.vector.h"

#include "data.entity.h"

namespace Data
{
    class CEnemySystem
    {
    public:
        enum EViewDirection
        {
            DOWN,
            UP,
            LEFT,
            RIGHT
        };

    public:

        static CEnemySystem& GetInstance()
        {
            static CEnemySystem instance;
            return instance;
        };

        CEnemySystem(const CEnemySystem&) = delete;
        CEnemySystem& operator = (const CEnemySystem&) = delete;

    public:
        CEntity* GetEnemy();
        void SetEnemy(CEntity* _pEnemy);

        double GetLastAttack();
        void SetLastAttack(double _Time);

        void SetDirection(EViewDirection _Direction);
        EViewDirection GetDirection();

        void Attack();

    public:
        void MoveEnemy(Core::Float2 _Distance);

    private:
        CEnemySystem()
            : m_Direction(DOWN)
            , m_lastAttack(0)
        {
        };

    private:
        enum EViewDirection m_Direction;
        double m_lastAttack;
        CEntity* m_Enemy;
    };
}