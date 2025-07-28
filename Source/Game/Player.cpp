#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"


void Player::Update(float dt)
{

	// make shit for rotation, thrusting and movement shit like that
	float rotate = 0;
	float speed = 200;
	float rotationRate = 0.0f;
	
	vec2 direction{ 0,0 };
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) {
		direction.y = -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) {
		direction.y = 1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_A)) {
		direction.x = -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_D)) {
		direction.x = 1;
	}

	m_transform.rotation *= (rotate * rotationRate) * dt;

	//TODO: find what you need to include


	if (direction.lengthSqr() > 0) {
		direction = direction.Normalized();
		m_transform.position += (direction * speed) * dt;
	}

	float thrust = 0;
	//if(scancodeshit)

	//m_transform.position.x = parabellum::math::Wrap(m_transform.position.x) i cant fucking see dude
	Actor::Update(dt);
}
