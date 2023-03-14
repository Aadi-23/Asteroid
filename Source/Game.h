#include "raylib.h"
#include "raymath.h"
#include "myMath.h"
#include <vector>

struct Entity
{
    float speed = 0.2;
    Vector2 dir{ 0,0 };
    float width = 80;
    float height = 60;
    Vector2 pos{100, 500};
};

class Level
{
    std::vector<Entity> all_entities;

public:
  
    Entity Player;
    Vector2 createmovement();
    int timer = 60;
    void movement(Vector2 pos);
    void spawnship();
    void spawnrock();

    void render();
    void update();
};