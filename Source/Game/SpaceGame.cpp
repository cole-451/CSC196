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

using namespace parabellum;
bool SpaceGame::initialize()
{

    m_scene = std::make_unique<Scene>();


    std::vector<vec2> model_points{ // player points for later.
       { -5, -6 },
    { 5, 0 },
    { -5, 6 },
    { -2, 0 },
    { -5, -6 },
    };
    // makes a square by connecting these points.

    // construct model with points above and preset color
    std::shared_ptr<Model> model = std::make_shared<Model>(model_points, vec3{ 1.0f, 0.5f, 0.0f });


    Transform tf(vec2{ 500,500 }, 0.0f, 1.0f);


    //declare and create actor
    std::vector<std::unique_ptr<Actor>> actors;

    Actor actor1(tf, model);
    std::unique_ptr<Player> player = std::make_unique<Player>(tf, model);
    actors.push_back(std::move(player));

    /*
    for (int i = 0; i < 10; i++) {
        Transform tf(vec2{ random::getrandomfloat(), random::getrandomfloat() }, 0.0f, 1.0f);

        Actor actor1(tf, model);
        std::unique_ptr<Player> player = std::make_unique<Player>(tf, model);
        actors.push_back(std::move(player));
    }
    
    
    
    */
    return false;
}

void SpaceGame::Update()
{
    for (int i = 0; i < 10; i++) {
        Transform transform{ vec2{ parabellum::random::getrandomfloat() * 1280, parabellum::random::getrandomfloat() * 1024 }, 0, 10 };
        //std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, model);
        //scene.AddActor(std::move(enemy)); God, why must this class be so frantic to follow?
    }
}

void SpaceGame::GTFO()
{
}

void SpaceGame::Draw()
{
    //m_scene->Draw(parabellum::getEngine()Draw());
}
