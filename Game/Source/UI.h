#pragma once
#include "Actor.h"
#include <vector>

class UI : public Actor
{
public:
	UI() { CreateModel(); }
	UI(Transform& transform) : Actor{ transform } { CreateModel(); }

	void CreateModel();
	void OnCollision(Actor* actor) override;

	void PopulateUI(Scene& scene);
};