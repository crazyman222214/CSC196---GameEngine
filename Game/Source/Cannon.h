#pragma once
#include "Player.h"

class Cannon : public Player
{
public:
	Cannon() { CreateModel(); }
	Cannon(Transform& transform) : Player{ transform } { CreateModel(); };
	Cannon(float speed, Transform& transform) : Player{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 2500;
};