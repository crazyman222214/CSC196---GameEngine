#include "SquareMan.h"
#include "Scene.h"
#include "Player.h"
#include "Color.h"
#include "Model.h"
#include "GameData.h"
#include <vector>

void SquareMan::CreateModel()
{
	std::vector<Vector2> points;
	points.push_back(Vector2{ 0, 0 });
	points.push_back(Vector2{ 5, 0 });
	points.push_back(Vector2{ 5, 5 });
	points.push_back(Vector2{ 0, 5 });
	points.push_back(Vector2{ 0, 0 });
	points.push_back(Vector2{ 1, 0 });
	points.push_back(Vector2{ 1, -2 });
	points.push_back(Vector2{ 1, 0 });
	points.push_back(Vector2{ 3, 0 });
	points.push_back(Vector2{ 3, -2 });


	m_health = 2;
	m_model = new Model(points, Color{1,0,0});
}

void SquareMan::Update(float dt)
{
	if (m_path)
	{
		//bool atNextPathPoint = m_transform.position == GameData::pathPoints[m_pathIndex + 1];
		Vector2 direction = (GameData::worldPathPoints[m_pathIndex + 1] - m_transform.position + m_path->GetTransform().position);
		float distance = direction.Length();

		if (m_pathIndex == 0)
		{
			m_velocity = direction.Normalized() * m_speed * dt;
			//m_velocity.y = ((m_velocity.y <= 0) ? m_velocity.y * -1 : m_velocity.y * 1);
			m_transform.rotation = direction.Angle();
		}
		if ((distance >= 1))
		{

			//If not at the next point, travel through the path at the given velocity
		}
		else if (m_pathIndex != GameData::pathPoints.size())
		{
			++m_pathIndex;
			direction = (GameData::worldPathPoints[m_pathIndex + 1] - m_transform.position + m_path->GetTransform().position);
			distance = direction.Length();
			m_velocity = direction.Normalized() * m_speed * dt;
			//m_velocity.y = ((m_velocity.y <= 0) ? m_velocity.y * -1 : m_velocity.y * 1);
			m_transform.rotation = direction.Angle();
		}
		Actor::Update(dt);
	}
}

void SquareMan::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Projectile")
	{
		m_health--;
		if (m_health == 0)
		{
			Enemy::OnCollision(actor);
		}
	}
	
}
