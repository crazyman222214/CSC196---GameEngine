#include "TriangleMan.h"
#include "Color.h"
#include "Model.h"
#include "Player.h"
#include "Scene.h"
#include "GameData.h"
#include <vector>

void TriangleMan::CreateModel()
{
	m_model = new Model{ GameData::TriangleManPoints, Color{0,1,0} };
	//m_lifespan = 1;
	
}

void TriangleMan::Update(float dt)
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


