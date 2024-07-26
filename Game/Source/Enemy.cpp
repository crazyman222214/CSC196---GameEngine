#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"
#include "GameData.h"
#include "Path.h"

void Enemy::Update(float dt)
{
	//Player* player = m_scene->GetActor<Player>();
	if (m_path)
	{
		bool atNextPathPoint = m_transform.position == GameData::pathPoints[m_pathIndex + 1];
		if (!atNextPathPoint)
		{
			Vector2 direction = GameData::pathPoints[m_pathIndex + 1] - m_transform.position + m_path->GetTransform().position;
			m_velocity = direction.Normalized() * m_speed * dt;
			m_transform.rotation = direction.Angle();

			//If not at the next point, travel through the path at the given velocity
			//Edge case: What if the enemy travels farther than the path for some reason?
		}

		/*Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity = direction.Normalized() * m_speed * dt;
		m_transform.rotation = direction.Angle();*/
	}
	Actor::Update(dt);
}

void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Projectile") {
		m_destroyed = true;
	}
}
