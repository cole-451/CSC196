#include "Actor.h"
#include "../Renderer/Model.h"

void parabellum::Actor::Update(float dt)
{
	
}

void parabellum::Actor::Draw(Renderer& renderer)
{
	m_model->Draw(renderer, m_transform);
}
