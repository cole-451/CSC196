#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include <memory>
#include <vector>
#include "../Core/StringHelper.h"


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
	Actor* Scene::getActorByName(const std::string& name) {
		//for (auto& actor : m_actors) {
			//if(actor->name == name){return	}
		return  nullptr;
	} 

	
	
	template <typename T>
	inline std::vector<T> Scene::getActorsByTag(const std::string& tag) {
		std::vector<T> results;
		for (auto& actor : actors) {
			if (toLower(actor->tag) == toLower(tag)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					results.push_back(object);
				}
			}
		}
		return results;
	}
	template<typename T>
	T* Scene::GetActorByName(const std::string& name)
	{

		std::vector<T> results;
		for (auto& actor : actors) {
			if (toLower(actor->name) == toLower(name)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					results.push_back(object);
				}
			}
		}
		return results;
	}

	

	
	
	
	//void Scene::AddActor(std::unique_ptr<Actor> actor)
	//{
	//	Find out why this is bugged.
	//}
}