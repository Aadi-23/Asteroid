#include "raylib.h"
#include "raymath.h"
#include "myMath.h"
#include <vector>
#include "Resources.h"

enum struct EntityKind
{
    SHIP,
    ASTEROID,
};


struct Entity
{
    EntityKind et;
    Vector2 dir{ 0,0 };
    Vector2 speed{ 0,0 };
    Vector2 size = { 0,0 };
    Vector2 pos = {0,0};
    float angle = 0.f;
};

class Level
{
    std::vector<Entity> all_entities;

public:
  
   
   
    int timer = 60;
    void movement();
    void spawnship();
    void spawnrock();

    void render();
    void update();
};