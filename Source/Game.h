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
    float speed = 0.2;
    Vector2 dir{ 0,0 };
    Vector2 size = { 0,0 };
    Vector2 pos = {0,0};
};

class Level
{
    std::vector<Entity> all_entities;

public:
  
   
    Vector2 createmovement();
    int timer = 60;
    void movement(Vector2 pos);
    void spawnship();
    void spawnrock();

    void render();
    void update();
};