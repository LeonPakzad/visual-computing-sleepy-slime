#pragma once

#include "../core/core.vector.h"

#include "data.entity.h"

namespace Data 
{
    class CPlayerSystem 
    {
        public:
            enum EViewDirection
            {
                UP,
                DOWN,
                LEFT,
                RIGHT
            };

        public:

            static CPlayerSystem& GetInstance()
            {
                static CPlayerSystem instance;
                return instance;
            };

            CPlayerSystem(const CPlayerSystem&) = delete;
            CPlayerSystem& operator = (const CPlayerSystem&) = delete;

        public:
            CEntity* GetPlayer();
            void SetPlayer(CEntity* _pPlayer);

            void SetDirection(EViewDirection _Direction);
            EViewDirection GetDirection();
            Core::Float2 GetPosition();

            void Die();
            void Revive();
            bool DeadSequenceIsOver();
            bool IsDead();
            double GetDiedAt();

        public:
            void MovePlayer(Core::Float2 _Distance);

        private:
            CPlayerSystem()
                : m_IsDead(false)
                , m_DiedAt(0.0)
                , m_ShowDeadMessageFor(5.0)
                , m_Direction(DOWN)
            {
            };

        private:
            enum EViewDirection m_Direction;

            bool m_IsDead;
            double m_DiedAt;
            double m_ShowDeadMessageFor;

            CEntity* m_Player;
    };
}