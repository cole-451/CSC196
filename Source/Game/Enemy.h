#pragma once
#include "Game/Actor.h"


class Enemy : public parabellum::Actor {
public:
	Enemy() = default;
	Enemy(const Transform& transform, class std::shared_ptr<parabellum::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;
private:



};