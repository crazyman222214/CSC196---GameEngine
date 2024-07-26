#pragma once
#include "Actor.h"

class Arrow : public Actor
{
public:
	Arrow() = default;
	Arrow(const Transform& transform) : Actor{ transform } { CreateModel(); }
	Arrow(float speed, const Transform& transform) : Actor{ transform }, m_speed{ speed } { CreateModel(); }
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	void CreateModel();
private:
	float m_speed = 0;
};