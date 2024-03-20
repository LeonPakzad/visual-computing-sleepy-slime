#pragma once

#include <string>
#include <vector>

#include "../data/data.entity.h"
#include "../core/core.vector.h"

namespace Logic
{
    class CSystem 
    {
        public:
            static CSystem& GetInstance()
            {
                static CSystem instance;
                return instance;
            }

            CSystem(const CSystem&) = delete;
            CSystem& operator = (const CSystem&) = delete;

        public:
            void OnTurn();

        public: 
            void HandleCommands();

            std::vector<Data::CEntity*> GetCollidingEntities(Core::CAABB2<float> _AABB);
            void HandleCollisions(std::vector<Data::CEntity*> _CollisionEntities, Data::CEntity* _CollidingEntity);
            void HandleCollisions(std::vector<Data::CEntity*> _CollisionEntities, Data::CEntity* _CollidingEntity, bool& _IsPlayerMovementBlocked);

            void MovePlayer(Core::Float2 _Orientation);
            void MoveBullets();

            void HandleMapEntities();

            void HandleEnemyDirection();

        private:
            CSystem() {};
    };
}