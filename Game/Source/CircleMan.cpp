#include "CircleMan.h"
#include "Model.h"
#include "Color.h"
#include "Player.h"
#include "Scene.h"
#include "GameData.h"
#include <vector>
void CircleMan::CreateModel()
{
	std::vector<Vector2> points;
	points.push_back(Vector2{ -4,5 });
	points.push_back(Vector2{ -4.5f,4.958f });
	points.push_back(Vector2{ -5.0f,4.828f });
	points.push_back(Vector2{ -5.5f,4.598f });
	points.push_back(Vector2{ -6.0f,4.236f });
	points.push_back(Vector2{ -6.5f,3.658f });
	points.push_back(Vector2{ -7.0f,2.0f });
	points.push_back(Vector2{ -6.5f,0.342f });
	points.push_back(Vector2{ -6.0f,-0.236f });
	points.push_back(Vector2{ -6.0f,-0.236f });
	points.push_back(Vector2{ -6.0f,-2.236f });
	points.push_back(Vector2{ -6.0f,-0.236f });
	points.push_back(Vector2{ -5.5f,-0.598f });
	points.push_back(Vector2{ -5.0f,-0.828f });
	points.push_back(Vector2{ -4.5f,-0.958f });
	points.push_back(Vector2{ -4,-1 });
	points.push_back(Vector2{ -3.5f,-0.958f });
	points.push_back(Vector2{ -3.0f,-0.828f });
	points.push_back(Vector2{ -2.5f,-0.598f });
	points.push_back(Vector2{ -2.0f,-0.236f });
	points.push_back(Vector2{ -2.0f,-2.236f });
	points.push_back(Vector2{ -2.0f,-0.236f });
	points.push_back(Vector2{ -1.5f,0.342f });
	points.push_back(Vector2{ -1.0f,2.0f });
	points.push_back(Vector2{ -1.5f,3.658f });
	points.push_back(Vector2{ -2.0f,4.236f });
	points.push_back(Vector2{ -2.5f,4.598f });
	points.push_back(Vector2{ -3.0f,4.828f });
	points.push_back(Vector2{ -3.5f,4.958f });
	points.push_back(Vector2{ -4,5 });

	m_model = new Model(points, Color{0,0,1});
}

void CircleMan::Update(float dt)
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
