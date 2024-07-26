#pragma once
#include "Enemy.h"


class TriangleMan : public Enemy
{
public:
	TriangleMan() {CreateModel();}
	TriangleMan(Transform& transform) : Enemy{ transform } { CreateModel(); };
	TriangleMan(Transform& transform, Path& path) : Enemy{ transform, path} { CreateModel(); };
	TriangleMan(float speed, Transform& transform) : Enemy{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 12000;
};