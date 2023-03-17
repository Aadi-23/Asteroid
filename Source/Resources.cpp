#include "Resources.h"


Textures ResourceManager::textures;
Sounds ResourceManager::sounds;

void ResourceManager::LoadResources()
{
	textures.ship = LoadTexture("./Resources/Textures/Ship.png");
	textures.rock = LoadTexture("./Resources/Textures/Rock.png");
}

void ResourceManager::UnloandResources()
{
	UnloadTexture(textures.ship);
	UnloadTexture(textures.rock);
}