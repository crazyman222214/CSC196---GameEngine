#include "Cannon.h"
#include "Scene.h"
#include "Arrow.h"
#include "Bomb.h"
#include <Engine.h>
void Cannon::CreateModel()
{
	std::vector<Vector2> points;

	for (float i = 0; i <= Math::DegToRad(360); i += (Math::TwoPi / 18))
	{
		points.push_back(Vector2{ Math::Cos(i), Math::Sin(i) } * 2);
	}
	//Ends at point {2,0}
	points.push_back({-2,0});
	points.push_back({0,0});
	points.push_back({0,2});
	points.push_back({0,-2});
	points.push_back({0,0});
	points.push_back({ Vector2{ Math::Cos(Math::DegToRad(45)), Math::Sin(Math::DegToRad(45)) } *2 });
	points.push_back({ Vector2{ -Math::Cos(Math::DegToRad(45)), -Math::Sin(Math::DegToRad(45)) } *2 });
	points.push_back({0,0});
	points.push_back({ Vector2{ Math::Cos(Math::DegToRad(135)), Math::Sin(Math::DegToRad(135)) } *2 });
	points.push_back({ Vector2{ -Math::Cos(Math::DegToRad(135)), -Math::Sin(Math::DegToRad(135)) } *2 });
	points.push_back({0,0});
	points.push_back({0,3});
	points.push_back({3,4});
	points.push_back({7,4});
	points.push_back({7,0});
	points.push_back({4,0});

	points.push_back(Vector2{ Math::Cos(Math::DegToRad(90)), Math::Sin(Math::DegToRad(90)) } * 2);
	
	//for (float i = Math::DegToRad(180); i >= Math::DegToRad(90); i -= (Math::TwoPi / 9))
	//{
	//	points.push_back((Vector2{ Math::Cos(i) -0.5f, Math::Sin(i) + 0.5f } *2) );
	//	
	//}

	//points.push_back(Vector2{Math::Cos(Math::DegToRad(70)), Math::Sin(Math::DegToRad(70)) } * 2*3 + 3);

	//points.push_back((Vector2{ Math::Cos(270) + 3, Math::Sin(270) + 3 } *2));

	m_radius = 75.0f;
	m_fireTime = 2.0f;
	m_fireTimer = m_fireTime;

	m_model = new Model(points, Color{0,0,1,1});
	m_unitRadius = std::make_unique<UnitRadius>(m_radius, Transform{ m_transform.position, 0, 1});
	
}

void Cannon::Update(float dt)
{
	if (m_fireTimer <= 0 && m_hasEnemyInRange && GetTag() == "Player")
	{
		m_fireTimer = m_fireTime * m_fireModifier;


		// actor
		Transform transform{ m_transform.position, m_transform.rotation, 3};

		auto arrow = std::make_unique<Bomb>(400, transform);
		arrow->SetLifespan(1);
		arrow->SetTag("Projectile");
		m_scene->AddActor(std::move(arrow));
		g_engine.GetAudio().PlaySound("Bomb.wav");
	}
	m_fireTimer -= dt;

	Player::Update(dt);
}
