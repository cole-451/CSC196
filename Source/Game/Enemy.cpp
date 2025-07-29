#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"
#include "Math/Math.h"

void Enemy::Update(float dt)
{
	//vec2 direction{0,0};

	//Actor* player = m_scene->GetActorByName("player");

	//if (player) {
		//direction = player->m_transform.position - m_transform.position;
		// 
	//}

	//transform.rotation = parabellum::math::radToDeg(direction.Angle());
}

void Enemy::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
		//scene->getGame()->addPoints(100);

	}
}
