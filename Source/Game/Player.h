#pragma once
#include "Framework/Actor.h"

using namespace parabellum;


class Player : public parabellum::Actor {
public:
	Player() = default;
	Player(const Transform& transform, class std::shared_ptr<parabellum::Model> model) :
		Actor{transform, model}
	{
	}


	void Update(float dt) override;
private:

};