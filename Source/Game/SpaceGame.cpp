#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "Player.h"
#include "Enemy.h"
#include "Math/Transform.h"
#include <memory>
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "GameData.h"
#include "Framework/Game.h"
using namespace parabellum;
bool SpaceGame::initialize() 
{

    m_scene = std::make_unique<Scene>();

    //declare and create actor list
    std::vector<std::unique_ptr<Actor>> actors;
    
    std::shared_ptr<Model> model = std::make_shared<Model>(GameData::shipPoints, vec3{ 1.0f, 0.5f, 0.0f });


    Transform tf(vec2{ 500,500 }, 0.0f, 5.0f);
    auto player = std::make_unique<Player>(tf, model);
    player->name = "Player";
    player->tag = "player";
    player->speed = 500;
    player->rotationRate = 2000;

    m_scene->AddActor(std::move(player));

    return false;

}

void SpaceGame::Update()
{
    
    m_scene->Update(getEngine().getTime().getDeltaTime());

    switch (current_state) {
    case GameState::Initialize:
        current_state = GameState::Title;
        break;

    case GameState::Title:
        
        //if space bar{
        current_state = GameState::StartGame;
        //}
        break;

    case GameState::StartGame:
        //m_score = 0;
        //m_lives = 3;
        //current_state = GameState::ComeGetSome;
        break;
    case GameState::ComeGetSome:
        //create player
        
        spawnEnemy();
        break;
    }
}

void SpaceGame::GTFO()
{
}

void SpaceGame::Draw(parabellum::Renderer& renderer)
{
    if (current_state == GameState::Title) {
        //m_titleFont->Load("Brianne_s")
    }
    m_scene->Draw(renderer);
}

void parabellum::SpaceGame::onPlayerDead()
{
    setLives(getLives()- 1);
}

void parabellum::SpaceGame::spawnEnemy()
{
    Actor* player = m_scene->GetActorByName("player");
    if (player) {

    }

    
    //create enemies
    //vec2 position = player->m_transform.position + parabellum::random::onUnitCircle() * parabellum::random::getReal(200, 500); // not finished
    
        Transform transform{ vec2{ parabellum::random::getReal() * 1280, parabellum::random::getReal() * 1024 }, 0, 10 };


        std::shared_ptr<Model> model = std::make_shared<Model>(GameData::enemyPoints, vec3{ 1.0f, 0.0f, 0.0f });
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, model);
        enemy->name = "enemy";
        enemy->tag = "enemy";
        enemy->speed = 350;
        m_scene->AddActor(std::move(enemy));
        // once again, this will not work until this can work with the actors list
    
}
