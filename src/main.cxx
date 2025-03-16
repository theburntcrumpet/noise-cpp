#include <raylib.h>

#include "include/WindowConsts.h"

void HandleInit()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
}

void DrawLoop()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Hello, Raylib", SCREEN_WIDTH / 5, SCREEN_HEIGHT / 2, 40, RED);
        EndDrawing();
    }
}

int main(int argc, char **argv)
{
    HandleInit();
    DrawLoop();
    CloseWindow();
    return 0;
}
