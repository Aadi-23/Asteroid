#include "raylib.h"

struct Textures
{
	Texture2D ship;
};

struct Sounds
{

};

struct ResourceManager
{
	static Textures textures;
	static Sounds sounds;

	static void LoadResources();
	static void UnloandResources();
};