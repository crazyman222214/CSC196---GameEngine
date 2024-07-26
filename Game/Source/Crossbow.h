#pragma once
#include "Player.h"

class Crossbow : public Player
{
public:
	Crossbow() { CreateModel(); }
	Crossbow(Transform& transform) : Player{ transform } { CreateModel(); };
	Crossbow(float speed, Transform& transform) : Player{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 2500;
};