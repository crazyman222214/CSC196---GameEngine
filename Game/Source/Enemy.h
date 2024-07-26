#pragma once
#include "Actor.h"
#include "Path.h"

class Enemy : public Actor
{
public:
	Enemy() = default;
	Enemy(const Transform& transform) : Actor{ transform } {}
	Enemy(const Transform& transform, Path& path) : Actor{ transform }, m_path{ &path } {}
	Enemy(const Transform& transform, Model* model) : Actor{ transform, model } {}
	Enemy(float speed, const Transform& transform, Model* model) : Actor{ transform, model }, m_speed{ speed } {}
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

	int m_pathIndex = 0;

protected:
	float m_speed = 0;
	float m_fireTimer = 0;
	Path* m_path{nullptr};
	bool m_atEnd = false;
};