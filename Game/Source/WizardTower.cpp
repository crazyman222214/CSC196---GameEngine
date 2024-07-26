#include "WizardTower.h"
#include "Scene.h"
#include "Lightning.h"
#include "Engine.h"
void WizardTower::CreateModel()
{
	std::vector<Vector2> points;
	points.push_back({0,1});
	points.push_back({4,0});
	points.push_back({4,-3});
	points.push_back({0,-4});
	points.push_back({0, 1});
	points.push_back({4,0});
	points.push_back({5,1});
	points.push_back({5,-4});
	points.push_back({4,-3});
	points.push_back({4,0});
	points.push_back({5,1});
	points.push_back({6,1});
	points.push_back({6,-4});
	points.push_back({5,-4});
	points.push_back({5,0});
	points.push_back({6,0});
	points.push_back({6,-1});
	points.push_back({5,-1});
	points.push_back({5,-2});
	points.push_back({6,-2});
	points.push_back({6,-3});
	points.push_back({5,-3});
	points.push_back({5,1});
	points.push_back({6,1});
	points.push_back({6,0});
	points.push_back({10.0f, -1.5f});
	points.push_back({6,-3});


	m_radius = 200.0f;
	m_fireTime = 4.0f;
	m_fireTimer = m_fireTime;

	m_model = new Model(points, Color{0,0,1,1});
	m_unitRadius = std::make_unique<UnitRadius>(m_radius, Transform{ Vector2{m_transform.position.x + GetRadius() / 4, m_transform.position.y - GetRadius() / 4}, 0, 1 });
}

void WizardTower::Update(float dt)
{
	if (m_fireTimer <= 0 && m_hasEnemyInRange && GetTag() == "Player")
	{
		m_fireTimer = m_fireTime * m_fireModifier;

		g_engine.GetAudio().PlaySound("Lightning.wav");
		// actor
		Transform transform{ m_transform.position, m_transform.rotation, 3 };

		auto lightning = std::make_unique<Lightning>(600, transform);
		lightning->SetLifespan(1);
		lightning->SetTag("Projectile");
		m_scene->AddActor(std::move(lightning));
	}

	m_fireTimer -= dt;
	Player::Update(dt);
}
