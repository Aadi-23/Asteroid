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

void Level::update()
{
	movement(createmovement());
}