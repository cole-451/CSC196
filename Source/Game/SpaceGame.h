#pragma once
#include "Framework/Game.h"
#include "Framework/Scene.h"
#include <memory>



class SpaceGame : parabellum::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		ComeGetSome, // game state
		HesRottingYouKnow, //death
		YouFuckingSuck, // gameover
	};
	SpaceGame() = default;

private:


	// Inherited via Game
	bool initialize() override;

	void Update() override;

	void GTFO() override;

	void Draw() override;

	std::unique_ptr<parabellum::Scene> m_scene;

	GameState current_state;

};