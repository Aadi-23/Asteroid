#include "raylib.h"
#include "Game.h"



int main(void)
{    
    enum screens { Start, Play, GameOver };
    const int screen_height = 800;
    const int screen_width = 1200;

    InitWindow(screen_width, screen_height, "Asteroid");

    InitAudioDevice();

    Level level;

    ResourceManager::LoadResources();

    screens sc = Start;

    level.spawnship();

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
            DrawText("GAME OVER", 450, 250, 50, RED);
            DrawText(TextFormat("Your Score Was : %i ", level.score), 400, 320, 40, GREEN);

           


            Vector2 retrysize = { 150,50 };
            Rectangle rectsrc = { 0,0, retrysize.x,retrysize.y };
            Rectangle rectdest = { GetScreenWidth()/2 - retrysize.x + 75,GetScreenHeight()/2,retrysize.x,retrysize.y};


            DrawTextureRec(ResourceManager::textures.Goback, rectsrc, Vector2{ rectdest.x, rectdest.y }, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (CheckCollisionPointRec(GetMousePosition(), rectdest))
                {
                    level.ResetLevel();
                    sc = Start; 
                }
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