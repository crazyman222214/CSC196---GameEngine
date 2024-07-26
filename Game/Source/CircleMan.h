#pragma once
#include "Enemy.h"


class CircleMan : public Enemy
{
public:
	CircleMan() { CreateModel(); }
	CircleMan(Transform& transform) : Enemy{ transform } { CreateModel(); };
	CircleMan(Transform& transform, Path& path) : Enemy{ transform, path } { CreateModel(); };
	CircleMan(float speed, Transform& transform) : Enemy{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 7000;
};
