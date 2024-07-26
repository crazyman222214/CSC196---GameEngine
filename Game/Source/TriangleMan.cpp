#include "TriangleMan.h"
#include "Color.h"
#include "Model.h"
#include "Player.h"
#include "Scene.h"
#include "GameData.h"
#include "Scene.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include <Engine.h>

void TriangleMan::CreateModel()
{
	std::vector<Vector2> points;

	points.push_back({ 0, 0 });
	points.push_back({ 2,4 });
	points.push_back({ 4,0 });
	points.push_back({ 0,0 });
	points.push_back({ 1,0 });
	points.push_back({ 1,-2 });
	points.push_back({ 1,0 });
	points.push_back({ 3,0 });
	points.push_back({ 3,-2 });

	m_model = new Model{ points, Color{0,1,0} };
	//m_lifespan = 1;
	
}

void TriangleMan::Update(float dt)
{
	if (m_path)
	{
		//bool atNextPathPoint = m_transform.position == GameData::pathPoints[m_pathIndex + 1];
		Vector2 direction = (GameData::worldPathPoints[m_pathIndex + 1] - m_transform.position + m_path->GetTransform().position );
		float distance = direction.Length();

		if (m_pathIndex == 0)
		{
			m_velocity = direction.Normalized() * m_speed * dt;
			//m_velocity.y = ((m_velocity.y <= 0) ? m_velocity.y * -1 : m_velocity.y * 1);
			m_transform.rotation = direction.Angle();
		}
		if ((distance >= 1 ))
		{

			//If not at the next point, travel through the path at the given velocity
		}
		else if (m_pathIndex != GameData::pathPoints.size() - 2)
		{
			++m_pathIndex;
			direction = (GameData::worldPathPoints[m_pathIndex + 1] - m_transform.position + m_path->GetTransform().position);
			distance = direction.Length();
			m_velocity = direction.Normalized() * m_speed * dt;
			//m_velocity.y = ((m_velocity.y <= 0) ? m_velocity.y * -1 : m_velocity.y * 1);
			m_transform.rotation = direction.Angle();
		}
		else if (m_pathIndex == GameData::pathPoints.size() - 2)
		{
			m_destroyed = true;
			m_scene->GetGame()->LoseLife();
		}
		Actor::Update(dt);
	}
}


