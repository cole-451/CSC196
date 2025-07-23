#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <string>
#include <memory>

namespace parabellum {
	class Actor {
	public:

		std::string name;
		std::string tag;

		Actor() = default;
		Actor(const Transform& transform, class std::shared_ptr<Model> model):
			m_transform{transform},
			m_model{model}
		{ }

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }
	protected:
		Transform m_transform;
		
		std::shared_ptr<Model> m_model;
	};
}