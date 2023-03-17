#include "Game.h"


void Level::movement()
{

	

	for (auto& e : all_entities)
	{
		switch (e.et)
		{
		case(EntityKind::SHIP):
		{
			if (IsKeyDown(KEY_A))
			{
				e.angle -= 80.f * GetFrameTime();
			}
			if (IsKeyDown(KEY_D))
			{
				e.angle += 80.f * GetFrameTime();
			}

			if (IsKeyDown(KEY_W))
			{
				e.speed.x += sinf(e.angle) * 80.f * GetFrameTime();
				e.speed.y += -cosf(e.angle) * 80.f * GetFrameTime();
			}
			if (!IsKeyDown(KEY_W))
			{
				e.speed.x -= sinf(e.angle) * 50.f * GetFrameTime();
				e.speed.y -= -cosf(e.angle) * 50.f * GetFrameTime();
			}
			

			e.pos.x += e.speed.x * GetFrameTime();
			e.pos.y += e.speed.y * GetFrameTime();



			if (e.pos.x < 0)
			{
				e.pos.x = e.pos.x + GetRenderWidth();
			}
			if (e.pos.x > GetRenderWidth())
			{
				e.pos.x = e.pos.x - GetRenderWidth();
			}

			if (e.pos.y < 0)
			{
				e.pos.y = e.pos.y + GetRenderHeight();
			}

			if (e.pos.y > GetRenderHeight())
			{
				e.pos.y = e.pos.y - GetRenderHeight();
			}
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

	Player.size = { 60,60 };
	Player.dir = { 0,0 };
	Player.et = EntityKind::SHIP;
	Player.speed = { 1,1 };
	Player.pos = {(float)(GetRenderWidth()/2), (float)(GetRenderHeight() / 2)};
	Player.angle = 0;

	all_entities.push_back(Player);
}


void Level::spawnrock()
{
	Entity Asteroid;

	Asteroid.pos = { (float)GetRandomValue(-20, GetRenderWidth()), 220 };
	Asteroid.dir = { (float)GetRandomValue(-2,2), (float)GetRandomValue(1,2) };
	Asteroid.speed = { 1,1 };
	Asteroid.size = { 30,30 };
	Asteroid.angle = 90;
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


			DrawTexturePro(ResourceManager::textures.ship, rectsrc, rectdest, Vector2(e.size.x/2, e.size.y/2),e.angle, WHITE);
			}
			break;
		case(EntityKind::ASTEROID):
			{
			Rectangle rectsrc = { 0,0, e.size.x, e.size.y };
			Rectangle rectdest = { e.pos.x,e.pos.y,e.size.x,e.size.y };


			DrawTexturePro(ResourceManager::textures.rock, rectsrc, rectdest, Vector2(e.size.x / 2, e.size.y / 2), e.angle * GetTime(), WHITE);
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
	movement();
}