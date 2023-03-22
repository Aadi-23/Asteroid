#include "raylib.h"
#include "Game.h"



int main(void)
{    
    enum screens { Start, Play, GameOver };
    const int screen_height = 800;
    const int screen_width = 1200;

    InitWindow(screen_width, screen_height, "Asteroid");

    Level level;

    ResourceManager::LoadResources();

    screens sc = Start;

    level.spawnship();

    InitAudioDevice();

    SetTargetFPS(60);

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

            DrawText("ASTEROID", GetRenderWidth() / 4, GetRenderHeight() / 4, 100, YELLOW);
            

            
            Rectangle SourceRec = { 0,0, 150, 60 };
            Rectangle StartButton = { (GetRenderWidth() / 2) - 150, (GetRenderHeight() / 2), 150, 60 };



            if (CheckCollisionPointRec(GetMousePosition(), StartButton))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    sc = Play;
                }
                
            }



            DrawTextureRec(ResourceManager::textures.startbutton, SourceRec, Vector2{ StartButton.x, StartButton.y }, WHITE);

            

            

            }
            break;
        case Play:
        {
            BeginDrawing();
            ClearBackground(BLACK);
            

            level.update();
            level.render();
           
            if (level.PlayerLives <= 0)
            {
                sc = GameOver;
            }
        }
        break;
        case GameOver:
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER", 450, 300, 50, RED);
            DrawText(TextFormat("Your Score Was : %i ", level.score), 400, 400, 40, GREEN);

            DrawText("Press R to Start again", 400, 450, 40, YELLOW);

            if (IsKeyPressed(KEY_R))
            {
                level.ResetLevel();

                sc = Play;
            }
        }
        break;
        default:
            break;
        }
        EndDrawing();

    }
    CloseWindow();

    ResourceManager::UnloandResources();

    return 0;
}