#include "Game.h"

void Level::movement()
{
	if (IsKeyDown(KEY_W))
	{
		Entity.dir.x += Entity.speed;
	}
	if (IsKeyDown(KEY_S))
	{
		Entity.dir.x -= Entity.speed;
	}
	if (IsKeyDown(KEY_D))
	{
		Entity.dir.y += Entity.speed;
	}
	if (IsKeyDown(KEY_A))
	{
		Entity.dir.y -= Entity.speed;
	}
}

void Level::spawnship()
{

}