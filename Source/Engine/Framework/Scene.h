#pragma once
#include <vector>
#include <memory> 
#include "Actor.h"

namespace parabellum {
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);

		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<Actor> actor);

		Actor* getActorByName(const std::string& name);


	private:
		std::vector<std::unique_ptr<class Actor>> actors;

	};
}
