#include "raylib.h"

struct Entity
{
    float speed = 2;
    Vector2 dir;
    float size;
};

class Level
{
    Entity Player;
    void movement();
    void spawnship();
};