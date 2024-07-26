#include "Lightning.h"
#include <Engine.h>

void Lightning::Update(float dt)
{
	for (int i = 0; i < 10; i++)
	{
		Particle::Data data{
			m_transform.position,
			Vector2(1,0).Rotate(randomf(Math::TwoPi)) * 50,
			randomf(0.5f,2.0f),
			100,100,100,255, };
		g_engine.GetPS().AddParticle(data);
	}

	m_velocity = Vector2{ 1, 0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}

void Lightning::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy") {
		m_destroyed = true;
	}
}

void Lightning::CreateModel()
{
	std::vector<Vector2> points;

	points.push_back({ 0,0 });
	points.push_back({ 3,-1 });
	points.push_back({ 3,1 });
	points.push_back({ 5,0 });

	m_model = new Model(points, Color{0,0,0,0});
}
