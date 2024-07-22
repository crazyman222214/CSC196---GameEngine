#include "CircleMan.h"
#include "Model.h"
#include "Color.h"
#include "Player.h"
#include "Scene.h"
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
	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity = direction.Normalized() * m_speed * dt;
		m_transform.rotation = direction.Angle();
	}
	Actor::Update(dt);
}
