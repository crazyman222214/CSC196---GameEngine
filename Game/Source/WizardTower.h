#pragma once
#include "Player.h"

class WizardTower : public Player
{
public:
	WizardTower() { CreateModel(); }
	WizardTower(Transform& transform) : Player{ transform } { CreateModel(); };
	WizardTower(float speed, Transform& transform) : Player{ transform } { CreateModel(); };

	void CreateModel();
	void Update(float dt);
private:
	float m_speed = 2500;
};