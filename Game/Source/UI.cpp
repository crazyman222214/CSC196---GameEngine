#include "UI.h"
#include "Crossbow.h"
#include "Scene.h"
#include "Game.h"
#include <memory>
#include "WizardTower.h"
#include "Cannon.h"


void UI::CreateModel()
{
	std::vector<Vector2> points;
	for (int i = 0; i < 3; i++)
	{
		int startX = 0;
		int startY = 0 - (i * 100);

		points.push_back({startX,startY});
		points.push_back({startX+100,startY});
		points.push_back({startX+100,startY-100});
		points.push_back({startX,startY-100});
		points.push_back({startX,startY});
		points.push_back({startX,startY-100});

	}

	m_model = new Model(points, Color{0,0,0,1});
}

void UI::OnCollision(Actor* actor)
{
}

void UI::PopulateUI(Scene& scene)
{
	//I am going to use a for loop for concise code but also making it easier to expand
	//i=0 == Crossbow
	//i=1 == Wizard Tower
	//i=2 == Cannon
	
	Transform crossbowTransform{ {m_transform.position.x + 50, m_transform.position.y + 50}, Math::DegToRad(270), 3 };
	auto crossbowUI = std::make_unique<Crossbow>(crossbowTransform);
	crossbowUI.get()->SetTag("UI");
	scene.AddActor(std::move(crossbowUI));

	Transform towerTransform{ {m_transform.position.x + 45, m_transform.position.y + 150}, Math::DegToRad(270), 3 };
	auto towerUI = std::make_unique<WizardTower>(towerTransform);
	towerUI.get()->SetTag("UI");
	scene.AddActor(std::move(towerUI));

	Transform cannonTransform{ {m_transform.position.x + 45, m_transform.position.y + 250}, Math::DegToRad(270), 3 };
	auto cannonUI = std::make_unique<Cannon>(cannonTransform);
	cannonUI.get()->SetTag("UI");
	scene.AddActor(std::move(cannonUI));
}
