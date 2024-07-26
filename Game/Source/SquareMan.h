#pragma once
#include "Enemy.h"


class SquareMan : public Enemy
{
public:
	SquareMan() { CreateModel(); }
	SquareMan(Transform& transform) : Enemy{ transform } { CreateModel(); };
	SquareMan(Transform& transform, Path& path) : Enemy{ transform, path} { CreateModel(); };
	SquareMan(float speed, Transform& transform) : Enemy{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
	void OnCollision(Actor* actor) override;
private:
	float m_speed = 5000;
	float m_health = 0;
};