#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <memory>

namespace parabellum {
	class Actor {
	public:
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
		//Model* m_model = nullptr;
		std::shared_ptr<Model> m_model;
	};
}