#pragma once
#include "Actor.h"

class Lightning : public Actor
{
public:
	Lightning() = default;
	Lightning(const Transform& transform) : Actor{ transform } { CreateModel(); }
	Lightning(float speed, const Transform& transform) : Actor{ transform }, m_speed{ speed } { CreateModel(); }
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	void CreateModel();
private:
	float m_speed = 0;
};