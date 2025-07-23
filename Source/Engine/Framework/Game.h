#pragma once
#include "Scene.h"

#include <memory>
namespace parabellum {
	class Game {
	public:
		Game() = default;




		virtual bool initialize() = 0;
		virtual void Update() = 0;
		virtual void GTFO() = 0;
		virtual void Draw() = 0;
	
	
	private:
		std::unique_ptr<Scene> m_scene;
	};


}