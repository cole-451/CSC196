#include "Actor.h"
#include "../Renderer/Model.h"

void parabellum::Actor::Update(float dt)
{
	// m_transform does huh times dt;
	m_transform.position += velocity * dt;
	//velocity *= 0; the overloads are const and DO NOT like this
}

void parabellum::Actor::Draw(Renderer& renderer)
{
	m_model->Draw(renderer, m_transform);
}
