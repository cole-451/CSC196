#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "GameData.h"
#include "Bullet.h"
#include <iostream>
#include "Framework/Scene.h"
#include "SpaceGame.h"
#include "Framework/Game.h"




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
	//std::cout << m_transform.rotation << std::endl;
		//m_transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) thrust = -1;
	vec2 direction{ 1,0 };
	vec2 force = direction.Rotate(math::degrees_to_radius(m_transform.rotation)) * thrust * speed;
	velocity += force * dt;
	// Can only move back and forth, so thrust does technically work!



	//check button to fire bullet!

	if (parabellum::getEngine().getInputSys().GetMouseButtonPressed(InputSystem::MouseButton::MOUSE_LEFT)) {
		getEngine().getAudioSys().playSound("shoot");
		std::shared_ptr<Model> model = std::make_shared<Model>(GameData::bulletPoints, vec3{ 1.0f, 1.0f, 1.0f });


		Transform tf(this->m_transform.position, this->m_transform.rotation, 20);
		auto bullet = std::make_unique<Bullet>(tf, model);
		bullet->name = "Bullet";
		bullet->tag = "player";
		bullet->speed = 9999999;
		bullet->lifespan = 2.0f;
		m_scene->AddActor(std::move(bullet));
		// problem with the scene? it seems like its not pointing to a real scene when its out of update.
		// upon further review, it is something to do with the list; i dont think it can fully add bullet
		// when AddActor is calling this, it cannot seem to actually connect the scene or game? I'm confused. m_game is null there.
	}

	//ADDITIONAL: later, we can make some homing rockets or a ray that can make enemies join us
	m_transform.position.x = parabellum::math::Wrap(m_transform.position.x, 0.0f, 1280.0f);
	m_transform.position.y = parabellum::math::Wrap(m_transform.position.y, 0.0f, 1024.0f);

	Actor::Update(dt);
}

void Player::onCollision(Actor* other)
{
	if (tag != other->tag) {
		/*if (m_scene->getGame()->getLives() > 0) {
			m_scene->getGame()->setLives(m_scene->getGame()->getLives() - 1);
			return;
		}*/
		stillAlive = false;

		dynamic_cast<SpaceGame*>(m_scene->getGame())->onPlayerDead();
		//getEngine().GTFO();
		//exit(1);
	}
}
