#include "Game.h"

Vector2 Level::createmovement()
{
	int LeftRight = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
	int UpDown = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W));
	Vector2 movement { LeftRight, UpDown };

	return Vector2Normalize(movement);
}

void Level::movement(Vector2 pos)
{
	Player.pos += pos * Player.speed;
}

void add_entity(const Entity entities)
{
	
}

void Level::spawnrock()
{
	Asteroid.pos = { (float)GetRandomValue(-20, GetRenderWidth()), 220 };
	Asteroid.dir = { (float)GetRandomValue(-2,2), (float)GetRandomValue(1,2) };
	Asteroid.speed = GetRandomValue(1, 2);
	Asteroid.height = 30;
	Asteroid.width = 30;
}

void Level::update()
{
	timer--;
	if (timer == 0)
	{
		timer = 60;
		spawnrock();
	}
	movement(createmovement());
}