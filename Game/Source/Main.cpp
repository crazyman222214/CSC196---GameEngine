#include "Engine.h"
#include "Player.h"
#include "Scene.h"
#include "Enemy.h"
#include "TriangleMan.h"
#include "SquareMan.h"
#include "CircleMan.h"
#include "MyGame.h"


#include <iostream>
#include <cstdlib>
#include <vector>


int main(int argc, char* argv[])
{
	g_engine.Initialize();
	MyGame* game = new MyGame(&g_engine);
	game->Initialize();

	while (!g_engine.IsQuit())
	{
		g_engine.Update();
		game->Update(g_engine.GetTime().GetDeltaTime());


		g_engine.GetRenderer().SetColor(255, 255, 255, 0);
		g_engine.GetRenderer().BeginFrame();

		game->Draw(g_engine.GetRenderer());
		g_engine.GetRenderer().EndFrame();

	}

	g_engine.Shutdown();
	return 0;
}
