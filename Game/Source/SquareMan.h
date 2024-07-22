#pragma once
#include "Enemy.h"


class SquareMan : public Enemy
{
public:
	SquareMan() { CreateModel(); }
	SquareMan(Transform& transform) : Enemy{ transform } { CreateModel(); };
	SquareMan(float speed, Transform& transform) : Enemy{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 2500;
};