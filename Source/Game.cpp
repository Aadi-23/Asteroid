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
				e.angle -= 5.f;
			}
			if (IsKeyDown(KEY_D))
			{
				e.angle += 5.f;
			}

			if (IsKeyDown(KEY_W))
			{
				if (e.acceleration < 4)
					e.acceleration += 0.04f;
			}
			else
			{
				if (e.acceleration > 0) 
					e.acceleration -= 0.02f;
				else if (e.acceleration < 0) 
					e.acceleration = 0;
			}

			e.speed.x = sinf(e.angle * DEG2RAD);
			e.speed.y = -cosf(e.angle * DEG2RAD);

			
			// Updates rocket speed
			e.pos += e.speed * e.acceleration;
		



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

		case(EntityKind::BULLETS):
		{
			e.pos += e.dir * e.speed;
            

			if (e.pos.x < 0 || e.pos.x > GetRenderWidth() || e.pos.y < 0 || e.pos.y > GetRenderHeight())
			{
				// die
			}
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
	Player.speed = { 0,0 };
	Player.pos = {(float)(GetRenderWidth()/2), (float)(GetRenderHeight() / 2)};
	Player.angle = 0;
	Player.acceleration = 0;


	all_entities.push_back(Player);
}


void Level::spawnrock()
{
	Entity Asteroid;

	Asteroid.pos = { (float)GetRandomValue(-20, GetRenderWidth()), 220 };
	Asteroid.dir = { (float)GetRandomValue(-2,2), (float)GetRandomValue(1,2) };
	Asteroid.speed = { 1,1 };
	Asteroid.size = { 150,150 };
	Asteroid.radius = 75;
	Asteroid.angle = 90;
	Asteroid.et = EntityKind::ASTEROID;

	all_entities.push_back(Asteroid);

}

void Level::Shoot()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Entity bullet;

		bullet.pos = all_entities[0].pos;
		bullet.dir = all_entities[0].speed;
		bullet.speed = { 8,8 };
		bullet.size = { 20,20 };
		bullet.radius = 10;
		bullet.angle = 0;
		bullet.et = EntityKind::BULLETS;

		all_entities.push_back(bullet);
	}
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


			DrawTexturePro(ResourceManager::textures.rock, rectsrc, rectdest, Vector2(e.size.x / 2, e.size.y / 2), (float)(e.angle * GetTime()), WHITE);
			
			}
			break;
		case(EntityKind::BULLETS):
		{
			DrawCircle(e.pos.x, e.pos.y, e.radius, GRAY);
		}
		break;
		}

	
	}
}

void Level::update()
{
	timer--;
	if (timer == 0 && MaxAsteroids > 0)
	{
		timer = 60;
		MaxAsteroids--;
		spawnrock();
	}

	Shoot();
	movement();
}