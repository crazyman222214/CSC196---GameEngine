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


	return 0;
}
/*
	//Create Systems

	std::vector<Particle> particles;
	float offset = 0;


	std::vector<Vector2> points;

	

	Model model{ points, Color{ 1,0,0 } };

	
	

	std::vector<Vector2> points3;
	points3.push_back(Vector2{-4,5});
	points3.push_back(Vector2{-4.5f,4.958f});
	points3.push_back(Vector2{-5.0f,4.828f});
	points3.push_back(Vector2{-5.5f,4.598f});
	points3.push_back(Vector2{-6.0f,4.236f});
	points3.push_back(Vector2{-6.5f,3.658f});
	points3.push_back(Vector2{-7.0f,2.0f});
	points3.push_back(Vector2{-6.5f,0.342f});
	points3.push_back(Vector2{-6.0f,-0.236f});
	points3.push_back(Vector2{ -6.0f,-0.236f });
	points3.push_back(Vector2{ -6.0f,-2.236f });
	points3.push_back(Vector2{ -6.0f,-0.236f });
	points3.push_back(Vector2{-5.5f,-0.598f});
	points3.push_back(Vector2{-5.0f,-0.828f});
	points3.push_back(Vector2{-4.5f,-0.958f});
	points3.push_back(Vector2{-4,-1});
	points3.push_back(Vector2{-3.5f,-0.958f});
	points3.push_back(Vector2{-3.0f,-0.828f});
	points3.push_back(Vector2{-2.5f,-0.598f});
	points3.push_back(Vector2{-2.0f,-0.236f});
	points3.push_back(Vector2{ -2.0f,-2.236f });
	points3.push_back(Vector2{ -2.0f,-0.236f });
	points3.push_back(Vector2{-1.5f,0.342f});
	points3.push_back(Vector2{-1.0f,2.0f});
	points3.push_back(Vector2{-1.5f,3.658f});
	points3.push_back(Vector2{-2.0f,4.236f});
	points3.push_back(Vector2{-2.5f,4.598f});
	points3.push_back(Vector2{-3.0f,4.828f});
	points3.push_back(Vector2{-3.5f,4.958f});
	points3.push_back(Vector2{-4,5});
	Model* model3 = new Model{ points3, Color{0,0,1} };

	Scene* scene = new Scene();

	Transform transform{ {300, 300}, 0, 5 };
	TriangleMan* triangleMan = new TriangleMan(transform);
	triangleMan->SetTag("Enemy");
	scene->AddActor(triangleMan);

	Transform transform3{ {600, 300}, 0, 5 };
	SquareMan* squareMan = new SquareMan(transform3);
	squareMan->SetTag("Enemy");
	scene->AddActor(squareMan);

	Transform transform4{ {300, 600}, 0, 5 };
	CircleMan* circleMan = new CircleMan(transform4);
	circleMan->SetTag("Enemy");
	scene->AddActor(circleMan);

	

	float spawnTimer = 2;

	




	Vector2 position{ 400, 300 };
	// >> Binary shift operator - shifts the bits by a given number, from left to right (1000 -> 0100)



	//Main loop
	while (!g_engine.IsQuit())
	{
		g_engine.Update();
		

		//std::cout << time.GetTime() << std::endl;
		//audio->playSound(sound, 0, false, nullptr);
		//input
		//update
		//Draw

		//INPUT

		spawnTimer -= g_engine.GetTime().GetDeltaTime();
		if (spawnTimer <= 0)
		{
			Transform tran{ {200,200}, 0, 2 };
			TriangleMan* enemy = new TriangleMan(tran);
			enemy->SetTag("Enemy");
			scene->AddActor(enemy);
			spawnTimer = 2;

			Transform tran2{ {600, 300}, 0, 2 };
			SquareMan* enemy2 = new SquareMan(tran2);
			enemy2->SetTag("Enemy");
			scene->AddActor(enemy2);
		}
		
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_Q) && g_engine.GetInput().GetPrevKeyDown(SDL_SCANCODE_Q)) g_engine.GetAudio().PlaySound("Test.wav");
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W) && g_engine.GetInput().GetPrevKeyDown(SDL_SCANCODE_W)) g_engine.GetAudio().PlaySound("Test.wav");
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_E) && g_engine.GetInput().GetPrevKeyDown(SDL_SCANCODE_E)) g_engine.GetAudio().PlaySound("Test.wav");

		
		//UPDATE
		scene->Update(g_engine.GetTime().GetDeltaTime());
		Vector2 mousePosition = g_engine.GetInput().GetMousePosition();
		/*if (g_engine.GetInput().GetMouseButtonDown(0))
		{
			for (int i = 0; i < 200000; i++)
			{
				particles.push_back(Particle{ mousePosition, RandomOnUnitCircle() * randomf(1000, 10300), randomf(0.1f, 5)});

			}
		}

		for (Particle& particle : particles)
		{
			particle.Update(g_engine.GetTime().GetDeltaTime());
			if (particle.m_position.x > 800) particle.m_position.x = 0;
			if (particle.m_position.x < 0) particle.m_position.x = 800;
			if (particle.m_position.y > 600) particle.m_position.y = 0;
			if (particle.m_position.y < 0) particle.m_position.y = 600;
		}
		//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;

		if (g_engine.GetInput().GetMouseButtonDown(0) && !g_engine.GetInput().GetPrevMouseButtonDown(0))
		{
			points.push_back(mousePosition);
		}

		if (g_engine.GetInput().GetMouseButtonDown(0) && g_engine.GetInput().GetPrevMouseButtonDown(0))
		{
			float distance = (points.back() - mousePosition).Length();

			if (distance > 3) points.push_back(mousePosition);
		}


		//DRAW
		//// clear screen

		//Background color
		g_engine.GetRenderer().SetColor(255,255, 255, 0);
		g_engine.GetRenderer().BeginFrame();
		//renderer.SetColor(255, 255, 255, 0);
		

		//// draw line
		
		for (Particle particle : particles)
		{
			particle.Draw(g_engine.GetRenderer());
			
			
		}

		scene->Draw(g_engine.GetRenderer());
		//model2.Draw(g_engine.GetRenderer(), transform);
		//model3.Draw(g_engine.GetRenderer(), transform);

		g_engine.GetRenderer().EndFrame();
	}

	return 0;
}
*/