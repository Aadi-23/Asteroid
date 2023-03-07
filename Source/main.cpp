#include "raylib.h"
#include "Game.h"

int main(void)
{    
    enum screens { Start, Asteroid, GameOver };
    const int screen_height = 800;
    const int screen_width = 1200;
    int score = 0;
    bool death = false;
    
    screens sc = Start;
    

    InitWindow(screen_width, screen_height, "Asteroid");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch (sc)
        {

        case Start:
            {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Press Any Key To Start", 250, 400, 50, WHITE);
            if (GetKeyPressed())
            {
                sc = Asteroid;
            }

            }
            break;
        case Asteroid:
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("Score:%i ",score), 100, 400, 50, WHITE);
            DrawRectangle();
            if (death == true)
            {
                sc = GameOver;
            }
        }
        break;
        case GameOver:
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER", 500, 600, 100, RED);
            DrawText(TextFormat("Your Score Was%i ", score), 500, 500, 50, GREEN);
        }
        break;
        default:
            break;
        }
        EndDrawing();

    }
    CloseWindow();

    return 0;
}