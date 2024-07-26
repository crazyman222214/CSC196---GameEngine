#include "Bomb.h"
#include <Particle.h>
#include <Random.h>
#include <Engine.h>

void Bomb::Update(float dt)
{
	m_velocity = Vector2{ 1, 0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}

void Bomb::OnCollision(Actor* actor)
{

	for (int i = 0; i < 5; i++)
	{
		Particle::Data data{
			m_transform.position,
			Vector2(1,0).Rotate(randomf(Math::TwoPi)) * 50,
			randomf(0.5f,2.0f),
			100,100,100,100, };
		g_engine.GetPS().AddParticle(data);
	}
	if (actor->GetTag() == "Enemy") {
		m_destroyed = true;
		
	}
}

void Bomb::CreateModel()
{
	std::vector<Vector2> points;

	for (float i = 0; i <= Math::DegToRad(450); i += (Math::TwoPi / 23))
	{
		points.push_back(Vector2{ Math::Cos(i), Math::Sin(i) } *2);

	}

	points.push_back({-0.5f,3.5f});


	m_model = new Model(points, Color{0,0,0,0});
}
