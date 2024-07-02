#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"

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
	
	Vector2 v1{300, 100};
	Vector2 v2{600, 100};

	std::vector<Vector2> points;

	bool quit = false;
	//Main loop
	while (!quit)
	{
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
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		//SDL_RenderClear(renderer);

		//// draw line
		renderer.SetColor(255, 255, 255, 0);


		for (int i = 0;points.size() > 1 && i < points.size() - 1; i++)
		{
			renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}

		//
		renderer.EndFrame();
		//// show screen
		//
	}

	return 0;
}