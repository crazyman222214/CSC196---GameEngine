#include "SquareMan.h"
#include "Scene.h"
#include "Player.h"
#include "Color.h"
#include "Model.h"
#include <vector>

void SquareMan::CreateModel()
{
	std::vector<Vector2> points;
	points.push_back(Vector2{ 5, 0 });
	points.push_back(Vector2{ 10, 0 });
	points.push_back(Vector2{ 10, 5 });
	points.push_back(Vector2{ 5, 5 });
	points.push_back(Vector2{ 5, 0 });
	points.push_back(Vector2{ 6, 0 });
	points.push_back(Vector2{ 6, -2 });
	points.push_back(Vector2{ 6, 0 });
	points.push_back(Vector2{ 9, 0 });
	points.push_back(Vector2{ 9, -2 });

	m_model = new Model(points, Color{1,0,0});
}

void SquareMan::Update(float dt)
{
	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity = direction.Normalized() * m_speed * dt;
		m_transform.rotation = direction.Angle();
	}
	Actor::Update(dt);
}
