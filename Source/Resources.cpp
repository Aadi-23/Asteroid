#include "Resources.h"


Textures ResourceManager::textures;
Sounds ResourceManager::sounds;

void ResourceManager::LoadResources()
{
	textures.ship = LoadTexture("./Resources/Textures/ship.png");
}

void ResourceManager::UnloandResources()
{

}