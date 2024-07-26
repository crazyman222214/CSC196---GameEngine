#include "Crossbow.h"
#include "UnitRadius.h"
#include "Scene.h"
#include "Arrow.h"
#include <memory>
void Crossbow::CreateModel()
{
	std::vector<Vector2> points;

	points.push_back({-1,1});
	points.push_back({-1,-1});
	points.push_back({9,-1});
	points.push_back({9,1});
	points.push_back({-1,1});
	points.push_back({9,1});
	points.push_back({8,7});
	points.push_back({ 7.5f, 6.75f});
	points.push_back({ 7.0f,6.5f});
	points.push_back({ 7.5f,1.0f});
	points.push_back({9,1});
	points.push_back({9,-1});
	points.push_back({8,-7});
	points.push_back({ 7.5f,-6.75f});
	points.push_back({ 7.0,-6.5f});
	points.push_back({ 7.5f, -1.0f});
	points.push_back({ 7.0,-6.5f});
	points.push_back({ 7.25f,-6.75f});
	points.push_back({0,0});
	points.push_back({ 7.25f, 6.75f });

	m_radius = 100.0f;
	m_fireTime = 2.0f;
	m_fireTimer = m_fireTime;

	m_model = new Model(points, Color{0,0,1,1});
	m_unitRadius = std::make_unique<UnitRadius>(m_radius, Transform{ {m_transform.position.x + GetRadius() / 4, m_transform.position.y - GetRadius() / 4}, 0, 1 });
}

void Crossbow::Update(float dt)
{
	if (m_fireTimer <= 0 && m_hasEnemyInRange && GetTag() == "Player")
	{
		m_fireTimer = m_fireTime * m_fireModifier;


		// actor
		Transform transform{ m_transform.position, m_transform.rotation, 3 };

		auto arrow = std::make_unique<Arrow>(400, transform);
		arrow->SetLifespan(1);
		arrow->SetTag("Projectile");
		m_scene->AddActor(std::move(arrow));
	}
	m_fireTimer -= dt;

	Player::Update(dt);
}
