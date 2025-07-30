#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Math/Math.h"

void Enemy::Update(float dt)
{
	//vec2 direction{0,0};

	Actor* player = m_scene->GetActorByName("player");
	if (player) {
	vec2 direction{ 0,0 };
	direction = player->transform.position - transform.position;
	direction = direction.Normalized();
	transform.rotation = parabellum::math::radius_to_degrees(direction.Angle());

	}

	
}

void Enemy::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
		//scene->getGame()->addPoints(100);

	}
}
