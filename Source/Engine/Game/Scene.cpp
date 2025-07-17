#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include <memory>

namespace parabellum {
	void Scene::Update(float dt) {

	}

	void Scene::Draw(class Renderer& renderer) {
		for (auto& actor : actors) {
			actor->Draw(renderer);
		}
	}
	/*void Scene::AddActor(std::unique_ptr<Actor> actor)
	{
		//Find out why this is bugged.
	}*/
}