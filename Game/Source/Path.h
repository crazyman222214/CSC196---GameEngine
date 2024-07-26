#pragma once
#include "Actor.h"
#include <vector>

class Path : public Actor
{
public:
	Path() { CreateModel(); }
	Path(Transform& transform) : Actor{transform} { CreateModel(); }

	void CreateModel();
	void OnCollision(Actor* actor) override;
	
};