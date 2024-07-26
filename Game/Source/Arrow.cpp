#include "Arrow.h"

void Arrow::Update(float dt)
{
	m_velocity = Vector2{ 1, 0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}

void Arrow::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy") {
		m_destroyed = true;
	}
}

void Arrow::CreateModel()
{
	std::vector<Vector2> points;
	points.push_back({0,0});
	points.push_back({-5,0});
	points.push_back({-4,0});
	points.push_back({-5,-1});
	points.push_back({-4,0});
	points.push_back({-5,1});
	points.push_back({-4,0});
	points.push_back({0,0});
	points.push_back({0,-1});
	points.push_back({0, 1});
	points.push_back({2,0});
	points.push_back({0,-1});

	m_model = new Model(points, Color{0,0,0,0});
}
