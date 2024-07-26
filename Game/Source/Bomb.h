#pragma once
#include "Actor.h"

class Bomb : public Actor
{
public:
	Bomb() = default;
	Bomb(const Transform& transform) : Actor{ transform } { CreateModel(); }
	Bomb(float speed, const Transform& transform) : Actor{ transform }, m_speed{ speed } { CreateModel(); }
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	void CreateModel();
private:
	float m_speed = 0;
};