#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "gfx.playPhase.h"
#include "core/core.config.h"
#include "game/game.application.h"
#include "data/data.entity.h"
#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"
#include "data/data.enemySystem.h"
#include "data/data.mapSystem.h"
#include <core/core.time.h>

namespace Gfx
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        Game::CApplication& app = Game::CApplication::GetInstance();

        app.window.clear(sf::Color::Black);
        
        std::vector<Data::CEntity*> allEntities = Data::CEntitySystem::GetInstance().GetAll();
        Data::CPlayerSystem& playerSystem = Data::CPlayerSystem::GetInstance();
        Data::CEnemySystem& enemySystem = Data::CEnemySystem::GetInstance();
        Data::CEntity* player = new Data::CEntity;
        Data::CEntity* wizard = new Data::CEntity;

        std::vector<Data::CEntity*> props;
        std::vector<Data::CEntity*> obstacles;
        std::vector<Data::CEntity*> bullets;

        for(auto entity : allEntities)
        {
            if (entity == nullptr) 
            {
                continue;
            }

            switch (entity->category)
            {
                case Data::SEntityCategory::Character:
                    player = entity;
                    continue;
                case Data::SEntityCategory::Enemy:
                    wizard = entity;
                    continue;
                case Data::SEntityCategory::Prop:
                    props.push_back(entity);
                    continue;
                case Data::SEntityCategory::Obstacle:
                    obstacles.push_back(entity);
                    continue;
                case Data::SEntityCategory::Bullet:
                    bullets.push_back(entity);
                    continue;
                default:
                    break;
            }

            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);
            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
		}

        for (auto entity : props)
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);
            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
        }

        for (auto entity : obstacles)
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);
            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
        }

        for (auto entity : obstacles)
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);
            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
        }

        for (auto entity : bullets)
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);
            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
        }

        //draw wizard seperately
        if (wizard != nullptr)
        {
            sf::Texture* wizardTexture;
            sf::Sprite wizardSprite;

            wizardTexture = static_cast<sf::Texture*>(wizard->metaEntity->facets[0]);
            wizardSprite.setTexture(*wizardTexture);
            wizardSprite.setPosition(wizard->position[0], wizard->position[1]);


            wizardSprite.setOrigin({0, 0});
            wizardSprite.setScale(1, 1);

            switch (enemySystem.GetDirection())
            {
                case Data::CEnemySystem::EViewDirection::UP:
                    wizardTexture = static_cast<sf::Texture*>(wizard->metaEntity->facets[0]);
                    wizardSprite.setTexture(*wizardTexture);
                    break;

                case Data::CEnemySystem::EViewDirection::DOWN:
                    wizardTexture = static_cast<sf::Texture*>(wizard->metaEntity->facets[1]);
                    wizardSprite.setTexture(*wizardTexture);
                    break;

                case Data::CEnemySystem::EViewDirection::LEFT:
                    wizardTexture = static_cast<sf::Texture*>(wizard->metaEntity->facets[2]);
                    wizardSprite.setTexture(*wizardTexture);
                    break;

                case Data::CEnemySystem::EViewDirection::RIGHT:
                    wizardTexture = static_cast<sf::Texture*>(wizard->metaEntity->facets[3]);
                    wizardSprite.setTexture(*wizardTexture);
                    break;
            }

            app.window.draw(wizardSprite);
        }

        //draw player seperately
        if (player != nullptr)
        {
            sf::Texture* playerTexture;
            sf::Sprite playerSprite;

            playerTexture = static_cast<sf::Texture*>(player->metaEntity->facets[0]);
            playerSprite.setTexture(*playerTexture);
            playerSprite.setPosition(player->position[0], player->position[1]);
        
        
            playerSprite.setOrigin({0, 0});
            playerSprite.setScale(1, 1);

            switch (playerSystem.GetDirection())
            {
            case Data::CPlayerSystem::EViewDirection::LEFT:
                playerTexture = static_cast<sf::Texture*>(player->metaEntity->facets[0]);
                playerSprite.setTexture(*playerTexture);
                break;

            case Data::CPlayerSystem::EViewDirection::RIGHT:
                playerTexture = static_cast<sf::Texture*>(player->metaEntity->facets[1]);
                playerSprite.setTexture(*playerTexture);
                break;

            case Data::CPlayerSystem::EViewDirection::UP:
                playerTexture = static_cast<sf::Texture*>(player->metaEntity->facets[2]);
                playerSprite.setTexture(*playerTexture);
                break;

            case Data::CPlayerSystem::EViewDirection::DOWN:
                playerTexture = static_cast<sf::Texture*>(player->metaEntity->facets[3]);
                playerSprite.setTexture(*playerTexture);
                break;
            }

            if
                (!(
                    player->position[0] < Data::CMapSystem::GetInstance().GetViewBorderXStart() ||
                    player->position[0] > Data::CMapSystem::GetInstance().GetViewBorderXEnd() ||
                    player->position[1] < Data::CMapSystem::GetInstance().GetViewBorderYStart() ||
                    player->position[1] > Data::CMapSystem::GetInstance().GetViewBorderYEnd()
                    ))
            {
                sf::View view = app.window.getView();

                float centerX = player->position[0];
                float centerY = player->position[1];

                view.setCenter(centerX, centerY);


                app.window.setView(view);
            }
       
            app.window.draw(playerSprite);
        }



        if (playerSystem.IsDead())
        {
            sf::Font font;
            font.loadFromFile(Core::Config::fontsDir + "Xeliard.ttf");
                                   
            sf::Text gameOverMessage;
            gameOverMessage.setString("Game Over");
            gameOverMessage.setFont(font);
            gameOverMessage.setCharacterSize(150);
            gameOverMessage.setFillColor(sf::Color::Red);

            sf::Vector2f viewCenter = app.GetInstance().window.getView().getCenter();
            viewCenter.x = viewCenter.x - gameOverMessage.getLocalBounds().width / 2;
            viewCenter.y = viewCenter.y - gameOverMessage.getLocalBounds().height;
            gameOverMessage.setPosition(viewCenter);

            sf::Text scoreText;
            scoreText.setString("your score: " + std::to_string(static_cast <int> (std::floor(playerSystem.GetDiedAt()))));
            scoreText.setFont(font);
            scoreText.setCharacterSize(50);
            scoreText.setFillColor(sf::Color::Red);

            sf::Vector2f scoreView = app.GetInstance().window.getView().getCenter();
            scoreView.x = scoreView.x - gameOverMessage.getLocalBounds().width / 2;
            scoreView.y = scoreView.y + 100;
            scoreText.setPosition(scoreView);

            app.window.draw(gameOverMessage);
            app.window.draw(scoreText);
        }

        app.window.display();
    }

    void CPlayPhase::OnLeave() {}
}