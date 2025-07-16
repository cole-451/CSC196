#include "Model.h"
#include "Renderer.h"



namespace parabellum {
	void Model::Draw(class Renderer& renderer) {

		renderer.setColor(m_color.r, m_color.g, m_color.b);

		if (m_points.empty()) {
			return;
		}

		for (int i = 0; i < m_points.size() - 1; i++) {
			vec2 p1 = m_points[i];
			vec2 p2 = m_points[i + 1];
			renderer.drawline(p1.x, p1.y, p2.x, p2.y);
		}
	}
}