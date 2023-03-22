#include "raylib.h"

struct Textures
{
	Texture2D ship;
	Texture2D ship0;

	Texture2D Bullet;
	Texture2D rock;
	Texture2D MediumRock;
	Texture2D SmallRock;
	Texture2D startbutton;
	Texture2D Retry;

	Texture2D health;

	Texture2D Goback;

};

struct Sounds
{
	Sound shot;
	Music background;
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