#include "UnitRadius.h"
#include "Enemy.h"
#include <memory>
void UnitRadius::OnCollision(Actor* actor)
{
}

void UnitRadius::CreateModel()
{
	std::vector<Vector2> points;

	for (float i = 0; i <= Math::DegToRad(360); i += (Math::TwoPi / 24))
	{
		points.push_back(Vector2{Math::Cos(i), Math::Sin(i)} * m_radius);
	}

	m_model = new Model(points, Color{1,0,1,1});
}

void UnitRadius::Draw(Renderer& renderer)
{
	if (m_isActive) Actor::Draw(renderer);
}
