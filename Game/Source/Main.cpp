#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fmod.hpp>


int main(int argc, char* argv[])
{
	//Create Systems
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;

	FMOD::Sound* sound = nullptr;
	FMOD::System* audio;
	FMOD::System_Create(&audio);
	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	std::vector<FMOD::Sound*> sounds;
	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);
	

	std::vector<Particle> particles;
	float offset = 0;


	std::vector<Vector2> points;

	points.push_back(Vector2{ 5, 0 });
	points.push_back(Vector2{ 10, 0});
	points.push_back(Vector2{ 10, 5});
	points.push_back(Vector2{ 5, 5});
	points.push_back(Vector2{ 5, 0});
	points.push_back(Vector2{ 6, 0});
	points.push_back(Vector2{ 6, -2});
	points.push_back(Vector2{ 6, 0});
	points.push_back(Vector2{ 9, 0});
	points.push_back(Vector2{ 9, -2});

	Model model{ points, Color{ 1,0,0 } };


	std::vector<Vector2> points2;
	
	points2.push_back(Vector2{ 0,0 });
	points2.push_back(Vector2{ 2,4 });
	points2.push_back(Vector2{ 4,0 });
	points2.push_back(Vector2{ 0,0 });
	points2.push_back(Vector2{ 1,0 });
	points2.push_back(Vector2{ 1,-2 });
	points2.push_back(Vector2{ 1,0 });
	points2.push_back(Vector2{ 3,0 });
	points2.push_back(Vector2{ 3,-2 });

	Model model2{ points2, Color{0,1,0} };

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
	Model model3{ points3, Color{0,0,1} };


	Vector2 position{ 400, 300 };
	// >> Binary shift operator - shifts the bits by a given number, from left to right (1000 -> 0100)
	Transform transform{ {renderer.GetWidth() >> 1, renderer.GetHeight() >> 1}, 0, 5};

	float rotation = 0;


	//Main loop

	bool quit = false;
	

	while (!quit)
	{
		audio->update();
		
		time.Tick();
		//std::cout << time.GetTime() << std::endl;
		//audio->playSound(sound, 0, false, nullptr);
		//input
		//update
		//Draw

		//INPUT
		input.Update();
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
		
		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) audio->playSound(sounds[0], 0, false, nullptr);
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) audio->playSound(sounds[1], 0, false, nullptr);
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) audio->playSound(sounds[2], 0, false, nullptr);
	{
		// play bass sound, vector elements can be accessed like an array with [#]
	}

		float thrust = 0;
		if (input.GetKeyDown(SDL_SCANCODE_LEFT)) transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();
		if (input.GetKeyDown(SDL_SCANCODE_RIGHT)) transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();
		if (input.GetKeyDown(SDL_SCANCODE_UP)) thrust = 40;
		if (input.GetKeyDown(SDL_SCANCODE_DOWN)) thrust = -40;

		Vector2 velocity = Vector2{ thrust, 0.0f }.Rotate(transform.rotation);
		transform.position += velocity * time.GetDeltaTime();
		transform.position.x = Math::Wrap(transform.position.x, (float)renderer.GetWidth());
		transform.position.y = Math::Wrap(transform.position.y, (float)renderer.GetWidth());
		//transform.rotation = transform.rotation + time.GetDeltaTime();

		//UPDATE
		Vector2 mousePosition = input.GetMousePosition();
		if (input.GetMouseButtonDown(0))
		{
			for (int i = 0; i < 200000; i++)
			{
				particles.push_back(Particle{ mousePosition, RandomOnUnitCircle() * randomf(1000, 10300), randomf(0.1f, 5)});

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
			points.push_back(mousePosition);
		}

		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0))
		{
			float distance = (points.back() - mousePosition).Length();

			if (distance > 3) points.push_back(mousePosition);
		}


		//DRAW
		//// clear screen

		//Background color
		renderer.SetColor(255,255, 255, 0);
		renderer.BeginFrame();
		//renderer.SetColor(255, 255, 255, 0);
		

		//// draw line
		
		for (Particle particle : particles)
		{
			particle.Draw(renderer);
			
			
		}

		model.Draw(renderer, transform);
		model2.Draw(renderer, transform);
		model3.Draw(renderer, transform);

		renderer.EndFrame();
	}

	return 0;
}