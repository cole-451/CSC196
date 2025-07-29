#pragma once
#include <vector>
#include <memory> 
#include "Actor.h"
#include "../Core/StringHelper.h"
#include <list>

namespace parabellum {
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);

		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<Actor> actor);

		Actor* getActorByName(const std::string& name);

		template <typename T>

		std::vector<T> getActorsByTag(const std::string& tag);

		template<typename T = Actor>
		T* GetActorByName(const std::string& name);


	private:
		
		std::list<std::unique_ptr<class Actor>> actors;

	};
}
