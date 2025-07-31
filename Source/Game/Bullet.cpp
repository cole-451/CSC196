#include "Bullet.h"
#include "Engine.h"
#include "Player.h"
#include "Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "../Engine/Math/Vector2.h"


// When you get Enemy.cpp done, paste that shit here.

void Bullet::Update(float dt)
{
	vec2 force = vec2{ 1,0 }.Rotate(math::degrees_to_radius(m_transform.rotation)) * dt;
	velocity = force;

	//if i had the wrap command working, id put it here


	Actor::Update(dt);

}

void Bullet::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
	}
	
}
