#include "raylib.h"
#include "raymath.h"
#include "myMath.h"
#include <vector>
#include "Resources.h"

enum struct EntityKind
{
    SHIP,
    ASTEROID,
    BULLETS,
    MEDIUM_ASTEROID,
    SMALL_ASTEROID,
};


struct Entity
{
    EntityKind et;
    Vector2 dir{ 0,0 };
    Vector2 speed{ 0,0 };
    Vector2 size = { 0,0 };
    float radius = 0;
    float acceleration = 0;
    Vector2 pos = {0,0};
    float angle = 0.f;

    bool dead = false;
};

struct Math                  // I made this struct where i store my Mathmeticle function So I do not need them to write everytime i need them.
{
    static float random_float_01();
    static Vector2 random_direction();
};

class Level
{
    std::vector<Entity> all_entities;

public:

    int score = 0;
    int MaxAsteroids = 3;
    
    int PlayerLives = 3;


   
   
    int timer = 90;

    void spawnship();
    void spawnbullet(Vector2 pos, Vector2 dir);
    void spawnrock();
    void MediumAsteroid(Vector2 pos);
    void SmallAsteroid(Vector2 pos);
    
    void Shoot();
    void Entitiesmovement();
    void EntitiesCollisions();

    void RemoveEntities();
    void ResetLevel();

    void render();
    void update();
};