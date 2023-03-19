#include "Game.h"


float Math::random_float_01()                 // I took this function from galba which returns a random float for my random direction because raylib doesn't have.
{
	return rand() / static_cast<float>(RAND_MAX);
}

Vector2 Math::random_direction()             // 
{
	float angle = random_float_01() * 2 * PI;
	return Vector2{ cosf(angle),sinf(angle) };
}

void Level::spawnship()
{
	Entity Player;

	Player.size = { 60,60 };
	Player.dir = { 0,0 };
	Player.et = EntityKind::SHIP;
	Player.speed = { 0,0 };
	Player.pos = {(float)(GetRenderWidth()/2), (float)(GetRenderHeight() / 2)};
	Player.radius = Player.size.x/2;
	Player.angle = 0;
	Player.acceleration = 0;


	all_entities.push_back(Player);
}


void Level::spawnrock()
{
	Entity Asteroid;

	Asteroid.pos = { (float)GetRandomValue(-100, GetRenderWidth()), -100 };
	Asteroid.dir = Math::random_direction();
	Asteroid.speed = { (float)GetRandomValue(1,2), (float)GetRandomValue(1,2) };
	Asteroid.size = { 200,200 };
	Asteroid.radius = Asteroid.size.x/2;
	Asteroid.angle = 90;
	Asteroid.et = EntityKind::ASTEROID;

	all_entities.push_back(Asteroid);

}

void Level::MediumAsteroid(Vector2 pos)
{
	Entity mediumasteroid;

	mediumasteroid.pos = pos;
	mediumasteroid.dir = Math::random_direction();
	mediumasteroid.speed = { (float)GetRandomValue(1,2), (float)GetRandomValue(1,2)};
	mediumasteroid.size = { 120,120 };
	mediumasteroid.radius = mediumasteroid.size.x/2;
	mediumasteroid.angle = 90;
	mediumasteroid.et = EntityKind::MEDIUM_ASTEROID;

	all_entities.push_back(mediumasteroid);
}

void Level::SmallAsteroid(Vector2 pos)
{
	Entity smallasteroid;

	smallasteroid.pos = pos + Vector2{ (float)GetRandomValue(40, -40), (float)GetRandomValue(-40, 40) };
	smallasteroid.dir = Math::random_direction();
	smallasteroid.speed = {(float) GetRandomValue(1,2), (float) GetRandomValue(1,2)};
	smallasteroid.size = { 50,50 };
	smallasteroid.radius = smallasteroid.size.x/2;
	smallasteroid.angle = 90;
	smallasteroid.et = EntityKind::SMALL_ASTEROID;

	all_entities.push_back(smallasteroid);

}

void Level::spawnbullet(Vector2 pos, Vector2 dir)
{
	Entity bullet;

	bullet.pos = pos;
	bullet.dir = dir;
	bullet.speed = { 8,8 };
	bullet.size = { 20,20 };
	bullet.radius = bullet.size.x/2;
	bullet.angle = 0;
	bullet.et = EntityKind::BULLETS;

	all_entities.push_back(bullet);
}

void Level::Shoot()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		for (auto& e : all_entities)
		{
			if (e.et == EntityKind::SHIP)
			{
				spawnbullet(e.pos, e.speed);
			}
		}
	}
}



void Level::Entitiesmovement()
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
				if (e.acceleration < 5)
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

			// Wrap object around screen
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

		case(EntityKind::MEDIUM_ASTEROID):
		{
			e.pos += e.dir * e.speed;

			// Wrap object around screen
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

		case(EntityKind::SMALL_ASTEROID):
		{
			e.pos += e.dir * e.speed;

			if (e.pos.x < 0 || e.pos.x > GetRenderWidth() || e.pos.y < 0 || e.pos.y > GetRenderHeight())
			{
				e.dead = true;
			}
		}
		break;

		case(EntityKind::BULLETS):
		{
			e.pos += e.dir * e.speed;


			if (e.pos.x < 0 || e.pos.x > GetRenderWidth() || e.pos.y < 0 || e.pos.y > GetRenderHeight())
			{
				e.dead = true;
			}
		}
		break;
		}
	}
}


void Level::EntitiesCollisions()
{
	for (auto& e : all_entities)
	{
		switch (e.et)
		{
		case(EntityKind::SHIP):
		{
			for (auto& rock : all_entities)
			{
				switch (rock.et)
				{
				case(EntityKind::ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, rock.pos, rock.radius))
					{
						// Player loses health
						PlayerLives--;
						rock.dead = true;
						e.dead = true;
						MaxAsteroids++;

						spawnship();

						for (int i = 0; i < 2; i++)
						{
							MediumAsteroid(rock.pos);
						}
						
					}
				}
				break;

				case(EntityKind::MEDIUM_ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, rock.pos, rock.radius))
					{
						// Player loses health
						PlayerLives--;
						rock.dead = true;
						e.dead = true;

						spawnship();

						for (int i = 0; i < 2; i++)
						{
							SmallAsteroid(rock.pos);
						}
					}
				}
				break;

				case(EntityKind::SMALL_ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, rock.pos, rock.radius))
					{
						// Player loses health
						PlayerLives--;
						rock.dead = true;
						e.dead = true;

						spawnship();
					}
				}
				break;
				}
			}
		}
		break;

		case(EntityKind::ASTEROID):
		{

		}
		break;

		case(EntityKind::MEDIUM_ASTEROID):
		{

		}
		break;

		case(EntityKind::BULLETS):
		{
			for (auto& b : all_entities)
			{
				switch (b.et)
				{
				case(EntityKind::ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, b.pos, b.radius))
					{
						MaxAsteroids++;
						score += 50;
						b.dead = true;
						e.dead = true;

						for (int i = 0; i < 2; i++)
						{
							MediumAsteroid(b.pos);
						}

					}
				}
				break;

				case(EntityKind::MEDIUM_ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, b.pos, b.radius))
					{
						
						score += 30;
						b.dead = true;
						e.dead = true;
						for (int i = 0; i < 2; i++)
						{
							SmallAsteroid(b.pos);
						}

					}
				}
				break;

				case(EntityKind::SMALL_ASTEROID):
				{
					if (CheckCollisionCircles(e.pos, e.radius, b.pos, b.radius))
					{
						
						b.dead = true;
						e.dead = true;
						score += 15;
					}
				}
				break;
				}
			}
		}
		break;

		}
	}
}


void Level::RemoveEntities()
{
	auto last_entity = std::remove_if(all_entities.begin(), all_entities.end(), [](const Entity& e)->bool {return e.dead; });
	all_entities.erase(last_entity, all_entities.end());
}


void Level::ResetLevel()
{
	all_entities.clear();
	spawnship();

	score = 0;
	MaxAsteroids = 3;
	PlayerLives = 3;
}

void Level::render()
{

	// Score
	DrawText(TextFormat("Score:%i ", score), 75, 50, 30, WHITE);
	
	// Player lives render
	
	for (int i = 1; i < PlayerLives + 1; i++)
	{
		DrawCircle(75 * i, 120, 25, RED);
	}
	

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

		case(EntityKind::MEDIUM_ASTEROID):
		{
			DrawCircleV(e.pos, e.radius, BLUE);
		}
		break;

		case(EntityKind::SMALL_ASTEROID):
		{
			DrawCircleV(e.pos, e.radius, YELLOW);
		}
		break;

		}

	
	}
}




void Level::update()
{
	timer--;
	if (timer <= 0 && MaxAsteroids > 0)
	{
		timer = 90;
		MaxAsteroids--;
		spawnrock();
	}

	Shoot();
	Entitiesmovement();

	EntitiesCollisions();
	RemoveEntities();
}