#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"



void Player::Update(float dt)
{

	
	float rotate = 0;
	float thrust = 0;

	//rotate

	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_A)) {
		rotate += -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_D)) {
		rotate += 1;
	}
	vec2 mousepos = getEngine().getInputSys().getMousePos();
	m_transform.rotation = math::radius_to_degrees(( mousepos - m_transform.position).Angle()); // supposed to track mouse position to rotate
		
		m_transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) thrust = -1;
	vec2 direction{ 1,0 };
	vec2 force = direction.Rotate(math::degrees_to_radius(m_transform.rotation)) * thrust * speed;
	velocity += force * dt;
	// STILL CAN'T MOVE!!!

	/*
	
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) {
		direction.y += -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) {
		direction.y += 1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_A)) {
		direction.x += -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_D)) {
		direction.x += 1;
	} // pressing anything gets you "vector subscript out of range"

	if (direction.lengthSqr() > 0) {
		direction = direction.Normalized();
		m_transform.position += (direction * speed) * dt;
	}
	*/


	//TODO: find what you need to include



	//check button to fire bullet!

	//ADDITIONAL: later, we can make some homing rockets or a ray that can make enemies join us



	//m_transform.position.x = parabellum::math::Wrap(m_transform.position.x) i cant fucking see dude
	Actor::Update(dt);
}

void Player::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
		//dynamic_cast<SpaceGame*>(m_scene->GetGame())->OnPlayerDeath();
	}
}
