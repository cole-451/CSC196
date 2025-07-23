#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"


void Player::Update(float dt)
{
	float rotate = 0;
	float speed = 200;
	float rotationRate = 0.0f;
	
	vec2 direction{ 0,0 };
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) {
		direction.y = -1;
	}

	m_transform.rotation *= (rotate * rotationRate) * dt;

	//TODO: find what you need to include


	if (direction.lengthSqr() > 0) {
		direction = direction.Normalized();
		m_transform.position += (direction * speed) * dt;
	}
	Actor::Update(dt);
}
