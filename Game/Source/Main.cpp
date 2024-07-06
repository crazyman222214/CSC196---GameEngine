#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>


int main(int argc, char* argv[])
{
	//Create Systems
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;
	
	
	
	std::vector<Particle> particles;
	for (int i = 0; i < 0; i++)
	{
		
	}

	//Main loop

	bool quit = false;
	std::vector<Vector2> points;
	while (!quit)
	{
		time.Tick();
		//std::cout << time.GetTime() << std::endl;

		//input
		//update
		//Draw

		//INPUT
		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0))
		{
			for (int i = 0; i < 1000; i++)
			{
				particles.push_back(Particle{ mousePosition, { randomf(-300, 300), randomf(-300, 300)}, randomf(1,5)});

			}
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());
			if (particle.m_position.x > 800) particle.m_position.x = 0;
			if (particle.m_position.x < 0) particle.m_position.x = 800;
			if (particle.m_position.y > 600) particle.m_position.y = 0;
			if (particle.m_position.y < 0) particle.m_position.y = 600;
		}
		//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;

		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0))
		{
			std::cout << "Mouse pressed\n";
			points.push_back(mousePosition);
		}

		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0))
		{
			std::cout << "Mouse held\n";
			float distance = (points.back() - mousePosition).Length();

			if (distance > 3) points.push_back(mousePosition);
		}


		//DRAW
		//// clear screen

		//Background color
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		//// draw line
		renderer.SetColor(255, 255, 255, 0);
		for (Particle particle : particles)
		{
			particle.Draw(renderer);
			
			
		}


		/*for (int i = 0;points.size() > 1 && i < points.size() - 1; i++)
		{
			renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}*/

		//
		renderer.EndFrame();
		//// show screen
		//
	}

	return 0;
}