#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Core/Random.h"
#include "Player.h"

using namespace parabellum;
bool SpaceGame::initialize()
{
    std::vector<vec2> model_points{
       {-1, -3},
       {1, -3},
       {1,2},
       {-1, 2},
       {-1,-3},
    };
    // makes a square by connecting these points.

    // construct model with points above and preset color
    std::shared_ptr<Model> model = std::make_shared<Model>(model_points, vec3{ 0,0,1 });


    Transform tf(vec2{ 500,500 }, 0.0f, 1.0f);


    //declare and create actor
    std::vector<std::unique_ptr<Actor>> actors;
    for (int i = 0; i < 10; i++) {
        Transform tf(vec2{ random::getrandomfloat(), random::getrandomfloat() }, 0.0f, 1.0f);

        Actor actor1(tf, model);
        std::unique_ptr<Player> player = std::make_unique<Player>(tf, model);
        actors.push_back(std::move(player));
    }
    return false;
}

void SpaceGame::Update()
{
}

void SpaceGame::GTFO()
{
}

void SpaceGame::Draw()
{

}
