#include "Resources.h"


Textures ResourceManager::textures;
Sounds ResourceManager::sounds;

void ResourceManager::LoadResources()
{
	textures.ship = LoadTexture("./Resources/Textures/Ship.png");
	textures.rock = LoadTexture("./Resources/Textures/Rock.png");
	textures.startbutton = LoadTexture("./Resources/Textures/Start.png");
<<<<<<< HEAD

	sounds.background = LoadSound("./Resources/Sounds/Background.mp3");
	sounds.shot = LoadSound("./Resources/Sounds/Shot.mp3");
	sounds.rock_destruction = LoadSound("./Resources/Sounds/RockDestruction.mp3");
	sounds.thrust = LoadSound("./Resources/Sounds/Thrusters.mp3");
	sounds.L = LoadSound("./Resources/Sounds/L.wav");
=======
	textures.Bullet = LoadTexture("./Resources/Textures/Bullet.png");
	textures.MediumRock = LoadTexture("./Resources/Textures/MidRock.png");
	textures.SmallRock = LoadTexture("./Resources/Textures/SmallRock.png");
	textures.Retry = LoadTexture("./Resources/Textures/Retry.png");
	textures.ship0 = LoadTexture("./Resources/Textures/Ship0.png");
	textures.health = LoadTexture("./Resources/Textures/Health.png");
	textures.Goback = LoadTexture("./Resources/Textures/Goback.png");

>>>>>>> d4206079f40f92947ddd171f811cb26b6cc85084
}

void ResourceManager::UnloandResources()
{
	UnloadTexture(textures.ship);
	UnloadTexture(textures.rock);
	UnloadTexture(textures.startbutton);

	UnloadSound(sounds.background);
	UnloadSound(sounds.thrust);
	UnloadSound(sounds.rock_destruction);
	UnloadSound(sounds.shot);
}