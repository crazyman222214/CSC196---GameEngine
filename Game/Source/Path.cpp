#include "Path.h"
#include "Scene.h"
#include "Game.h"
#include "GameData.h"
void Path::CreateModel()
{
	m_model = new Model(GameData::pathPoints, Color{1,0,0,1});
}

void Path::OnCollision(Actor* actor)
{
}
