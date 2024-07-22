#pragma once
#include "Enemy.h"


class CircleMan : public Enemy
{
public:
	CircleMan() { CreateModel(); }
	CircleMan(Transform& transform) : Enemy{ transform } { CreateModel(); };
	CircleMan(float speed, Transform& transform) : Enemy{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 3000;
};
