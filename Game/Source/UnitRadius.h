#pragma once
#include "Actor.h"
#include "Enemy.h"
#include <memory>

class Renderer;

class UnitRadius : public Actor
{
public:
	UnitRadius() = default;
	UnitRadius(float radius, const Transform& transform) : Actor{ transform }, m_radius{ radius } { CreateModel(); }
	void CreateModel();
	void OnCollision(Actor* actor) override;
	void Draw(Renderer& renderer) override;
	
	void SetActive(bool isActive) { m_isActive = isActive; }
	bool GetActive() { return m_isActive; }

	float GetRadius() { return m_radius; };

private:
	float m_radius = 0.0f;
	bool m_isActive = false;
};