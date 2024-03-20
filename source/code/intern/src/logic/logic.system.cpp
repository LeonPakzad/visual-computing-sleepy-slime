#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

#include "../core/core.floatCompare.h"

#include "../data/data.playerSystem.h"
#include "../data/data.enemySystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.eventSystem.h"
#include "../data/data.mapSystem.h"
#include "../core/core.time.h"

namespace Logic 
{
    void CSystem::OnTurn()
    {
        HandleCommands();
        HandleMapEntities();

        Data::CPlayerSystem& playerSystem = Data::CPlayerSystem::GetInstance();

        if (playerSystem.IsDead() && playerSystem.DeadSequenceIsOver())
        {
            Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::PlayerDied);

            playerSystem.Revive();
        }
    }

    void CSystem::HandleCommands()
    {
        float verticalStep = -6.0f;
        float horizontalStep = 6.0f;

        CCommandSystem& commandSystem = CCommandSystem::GetInstance();
        CCommand* command;

        while (!commandSystem.CommandQueueIsEmpty())
        {
            command = &commandSystem.GetNextInQueue();

            switch (command->GetType())
            {
                case Data::SCommandAction::MoveLeft:
					MovePlayer(Core::Float2(-horizontalStep, 0));
					break;

                case Data::SCommandAction::MoveRight:
                    MovePlayer(Core::Float2(horizontalStep, 0));
					break;

				case Data::SCommandAction::MoveUp:
					MovePlayer(Core::Float2(0, verticalStep));
                    break;

                case Data::SCommandAction::MoveDown:
                    MovePlayer(Core::Float2(0, -verticalStep));
                    break;

                default:
                    break;
            }

            commandSystem.RemoveNextInQueue();
        }
    }

    std::vector<Data::CEntity*> CSystem::GetCollidingEntities(Core::CAABB2<float> _AABB)
    {
		std::vector<Data::CEntity*> entities = Data::CEntitySystem::GetInstance().GetAllCollidables();
		std::vector<Data::CEntity*> collidingEntities;

        for (Data::CEntity* entity : entities)
        {
            if (entity == nullptr)
            {
                continue;
            }

            if (_AABB.Intersects(entity->aabb) == true)
            {
                collidingEntities.push_back(entity);
            }
        }

        return collidingEntities;
    }

    void CSystem::HandleCollisions(std::vector<Data::CEntity*> _CollisionEntities, Data::CEntity* _CollidingEntity,  bool& _IsPlayerMovementBlocked)
    {
        for (Data::CEntity* entity : _CollisionEntities)
        {
            if (_CollidingEntity->category == Data::SEntityCategory::Character)
            {
                switch (entity->category)
                {
                    case Data::SEntityCategory::Obstacle:
                    case Data::SEntityCategory::Wall:
                        _IsPlayerMovementBlocked = true;
                        break;

                    case Data::SEntityCategory::Enemy:
                        Data::CPlayerSystem::GetInstance().Die();
                        break;

                    case Data::SEntityCategory::Bullet:
                        Data::CPlayerSystem::GetInstance().Die();
                        break;
                }
            }
        }
	}

    void CSystem::HandleCollisions(std::vector<Data::CEntity*> _CollisionEntities, Data::CEntity* _CollidingEntity)
    {
        for (Data::CEntity* entity : _CollisionEntities)
        {
            if (_CollidingEntity->category == Data::SEntityCategory::Bullet)
            {
                switch (entity->category)
                {
                    case Data::SEntityCategory::Character:
                        if (Data::CPlayerSystem::GetInstance().IsDead() == false)
                        {
                            Data::CPlayerSystem::GetInstance().Die();
                        }
                        break;

                    case Data::SEntityCategory::Wall:
                        Data::CEntitySystem::GetInstance().Destroy(*_CollidingEntity);
                        break;

                    case Data::SEntityCategory::Obstacle:
                        Data::CEntitySystem::GetInstance().Destroy(*entity);
                        Data::CEntitySystem::GetInstance().Destroy(*_CollidingEntity);
                        break;
                }
            }
        }
    }

    void CSystem::MovePlayer(Core::Float2 _Orientation)
    {
        Data::CPlayerSystem& playerSystem = Data::CPlayerSystem::GetInstance();
        Data::CEntity* player = playerSystem.GetPlayer();
        
        if(player == nullptr || playerSystem.IsDead()) 
        {
            return;
        }

        bool orientationXIsPositive = _Orientation[0] >= 0;
        bool orientationYIsPositive = _Orientation[1] >= 0;

        if (_Orientation[0] < 0 && _Orientation[1] == 0)
        {
            playerSystem.SetDirection(Data::CPlayerSystem::EViewDirection::LEFT);
        }

        if (_Orientation[0] > 0 && _Orientation[1] == 0)
        {
            playerSystem.SetDirection(Data::CPlayerSystem::EViewDirection::RIGHT);
        }

        if (_Orientation[0] == 0 && _Orientation[1] < 0)
        {
            playerSystem.SetDirection(Data::CPlayerSystem::EViewDirection::UP);
        }

        if (_Orientation[0] == 0 && _Orientation[1] > 0)
        {
            playerSystem.SetDirection(Data::CPlayerSystem::EViewDirection::DOWN);
        }

        // handle the collision
        Core::CAABB2<float> movedPlayerAabb = Core::CAABB2<float>(
            Core::Float2(
                player->position[0] + _Orientation[0] + 1,
                player->position[1] + _Orientation[1] + 1
            ),
            Core::Float2(
                player->position[0] + _Orientation[0] + (player->size[0] - 1),
                player->position[1] + _Orientation[1] + (player->size[1] - 1)
            )
        );
        bool* playerMovementIsBlocked = new bool(false);
        std::vector<Data::CEntity*> collidingEntities = GetCollidingEntities(movedPlayerAabb);
        HandleCollisions(collidingEntities, player , *playerMovementIsBlocked);

        if (!*playerMovementIsBlocked)
        {
            playerSystem.MovePlayer(_Orientation);
        }
    }

    void CSystem::HandleMapEntities()
    {
        Data::CEnemySystem& enemySystem = Data::CEnemySystem::GetInstance();

        HandleEnemyDirection();

        int gracePeriod = 3;
        double attackSpeed = 0.5;
        if (
            Core::Time::GetTime() > gracePeriod && 
            Core::Time::GetTime() - Data::CEnemySystem::GetInstance().GetLastAttack() > attackSpeed
           )
        {
            enemySystem.Attack();
        }

        MoveBullets();
    }

    void CSystem::MoveBullets()
    {
        double bulletMight = 13;
        std::vector<Data::CEntity*> bullets = Data::CEntitySystem::GetInstance().GetByCategory(Data::SEntityCategory::Bullet);
        for (auto& bullet : bullets)
        {

            if (bullet->position != bullet->destination)
            {
                bullet->position = Core::Float2(
                    bullet->position[0] + bullet->direction[0] / bulletMight,
                    bullet->position[1] + bullet->direction[1] / bulletMight
                );
                bullet->aabb = Core::CAABB2<float>(
                    Core::Float2(
                        bullet->position[0],
                        bullet->position[1]
                    ),
                    Core::Float2(
                        bullet->position[0] + bullet->size[0],
                        bullet->position[1] + bullet->size[1]
                    )
                );

                HandleCollisions(GetCollidingEntities(bullet->aabb), bullet);
            }
        }
    }

    void CSystem::HandleEnemyDirection()
    {
        Data::CEnemySystem& enemySystem = Data::CEnemySystem::GetInstance();
        Data::CEntity* enemy = enemySystem.GetEnemy();

        Data::CPlayerSystem& playerSystem = Data::CPlayerSystem::GetInstance();
        Data::CEntity* player = playerSystem.GetPlayer();

        int offsetToPlayerX = player->position[0] - enemy->position[0];
        int offsetToPlayerY = player->position[1] - enemy->position[1];

        if (abs(offsetToPlayerX) > abs(offsetToPlayerY))
        {
            if (player->position[0] < enemy->position[0])
            {
                enemySystem.SetDirection(Data::CEnemySystem::EViewDirection::LEFT);
            }

            if (player->position[0] > enemy->position[0])
            {
                enemySystem.SetDirection(Data::CEnemySystem::EViewDirection::RIGHT);
            }
        }
        else
        {
            if (player->position[1] < enemy->position[1])
            {
                enemySystem.SetDirection(Data::CEnemySystem::EViewDirection::UP);
            }

            if (player->position[1] > enemy->position[1])
            {
                enemySystem.SetDirection(Data::CEnemySystem::EViewDirection::DOWN);
            }
        }
    }
}