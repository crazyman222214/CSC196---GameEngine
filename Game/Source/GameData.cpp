#include "GameData.h"

namespace GameData
{
	const std::vector<Vector2> pathPoints{
		{0,0},
		{400,0},
		{300,-100},
		{550,-100},
		{600, -50},
		{550, 0},
		{500, -50},
		{550, -100},
		{650, -200},
		{650, -300},
		{0, -300},
	};

	const std::vector<Vector2> worldPathPoints{
		{0,0},
		{400,0},
		{300,100},
		{550,100},
		{600, 50},
		{550, 0},
		{500, 50},
		{550, 100},
		{650, 200},
		{650, 300},
		{0, 300},
	};
}