#pragma once
#include "Framework/Game.h"


class SpaceGame : parabellum::Game {
public:
	SpaceGame() = default;

private:


	// Inherited via Game
	bool initialize() override;

	void update() override;

	void GTFO() override;

	void Draw() override;

};