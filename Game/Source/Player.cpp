#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include "Scene.h"
#include "MyGame.h"
#include "Arrow.h"
#include <iostream>

void Player::Update(float dt)
{
	//Using this so I can set a difference between placed towers and UI
	if (this->GetTag() != "Player") return;

	//If there is a enemy in the range of the UnitRadius, it should change it's rotation to face the enemy and shoot
	//Edge case: what if there are multiple enemies in the UnitRadius

	Enemy* closestEnemy = dynamic_cast<Enemy*>( m_scene->GetClosestEnemyWithinRadius(*this, this->GetUnitRadius().get()->GetRadius()) );
	if (closestEnemy)
	{
		Vector2 direction = (closestEnemy->GetTransform().position - m_transform.position);
		m_transform.rotation = Vector2{ Math::Cos(direction.Angle()), Math::Sin(direction.Angle())}.Angle(); 
		m_hasEnemyInRange = true;
	}
	else
	{
		m_hasEnemyInRange = false;
	}
	

	

	Actor::Update(dt);
}

void Player::Draw(Renderer& renderer)
{
	m_unitRadius.get()->Draw(renderer);
	Actor::Draw(renderer);
}



void Player::OnCollision(Actor* actor)
{

}
