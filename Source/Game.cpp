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

	

	for (auto& e : all_entities)
	{
		switch (e.et)
		{
		case(EntityKind::SHIP):
			{
			  e.pos += pos * e.speed;
			}
			break;

		case(EntityKind::ASTEROID):
		{
			e.pos += e.dir * e.speed;
		}
		break;
		}
	}
}


void Level::spawnship()
{
	Entity Player;

	Player.size = { 40,40 };
	Player.dir = { 0,0 };
	Player.et = EntityKind::SHIP;
	Player.speed = 2;
	Player.pos = {(float)(GetRenderWidth()/2), (float)(GetRenderHeight() / 2)};

	all_entities.push_back(Player);
}


void Level::spawnrock()
{
	Entity Asteroid;

	Asteroid.pos = { (float)GetRandomValue(-20, GetRenderWidth()), 220 };
	Asteroid.dir = { (float)GetRandomValue(-2,2), (float)GetRandomValue(1,2) };
	Asteroid.speed = GetRandomValue(1, 2);
	Asteroid.size = { 30,30 };
	Asteroid.et = EntityKind::ASTEROID;

	all_entities.push_back(Asteroid);

}

void Level::render()
{

	
	
	
	for (auto& e : all_entities) 
	{
		switch (e.et)
		{
		case(EntityKind::SHIP):
			{
			
			Rectangle rectsrc = { 0,0, e.size.x, e.size.y };
			Rectangle rectdest = { e.pos.x,e.pos.y,e.size.x,e.size.y };


			DrawTexturePro(ResourceManager::textures.ship, rectsrc, rectdest, Vector2(e.size.x/2, e.size.y/2), GetTime() * 90, WHITE);
			}
			break;
		case(EntityKind::ASTEROID):
			{
			DrawRectangle(e.pos.x, e.pos.y, e.size.y, e.size.y, GRAY);
			}
			break;
		}

	
	}
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