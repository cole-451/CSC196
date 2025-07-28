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
	void Scene::AddActor(std::unique_ptr<Actor> actor)
	{
	}
	//Actor* Scene::getActorByName(const std::string& name) {
		//for (auto& actor : m_actors) {
			//if(actor->name == name){return	}
	//} Strange shit going on here. Comments are showing up where they shouldn't be.
	
	
	
	//void Scene::AddActor(std::unique_ptr<Actor> actor)
	//{
	//	Find out why this is bugged.
	//}
}