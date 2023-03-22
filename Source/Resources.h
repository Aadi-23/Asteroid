#include "raylib.h"

struct Textures
{
	Texture2D ship;
	Texture2D rock;
	Texture2D startbutton;
};

struct Sounds
{
	Sound shot;
	Sound background;
	Sound thrust;
	Sound rock_destruction;
	Sound L;
};

struct ResourceManager
{
	static Textures textures;
	static Sounds sounds;

	static void LoadResources();
	static void UnloandResources();
};