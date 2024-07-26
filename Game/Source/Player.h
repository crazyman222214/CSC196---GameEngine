#pragma once
#include "Actor.h"
#include "UnitRadius.h"
#include <memory>

class Player : public Actor
{
public:
	Player() = default;
	Player(const Transform& transform) : Actor{ transform } {}
	Player(const Transform& transform, Model* model) : Actor{ transform, model } {}
	Player(float speed, const Transform& transform, Model* model) : Actor{ transform, model }, m_speed{ speed } {}

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;
	virtual void OnCollision(Actor* actor);

	void SetFireModifier(float mod) { m_fireModifier = mod; }
	auto& GetUnitRadius() { return m_unitRadius; }

	
protected:
	std::unique_ptr<UnitRadius> m_unitRadius;
	float m_radius = 0.0f;
	float m_speed = 0;
	float m_fireTimer = 0;
	float m_fireTime = 0;
	float m_fireModifier = 1;
	bool m_hasEnemyInRange = false;
	
};