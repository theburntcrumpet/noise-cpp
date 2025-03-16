#include <raylib.h>
#include <vector>
#include "include/Noise.h"
#include "include/NoiseGenerator.h"
#include "include/SimplexNoiseStrategy.h"
#include "include/WindowConsts.h"

typedef std::vector<std::vector<Color>> color_vec;

void HandleInit()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(TARGET_FPS);
}

Color GetColorForValue(double n) {
    return (Color){ (unsigned char)(n* 100), (unsigned char)(n* 100), (unsigned char)(n* 100), 255};
}

color_vec GenerateColors(Noise noise) {
    color_vec colors(noise.GetWidth(), std::vector<Color>(noise.GetHeight()));
    vector_noise noiseVec = noise.GetNoise();
    for (size_noise x = 0; x < noise.GetWidth(); x++) {
        for (size_noise y = 0; y < noise.GetHeight(); y++) {
            colors[x][y] = GetColorForValue(noiseVec[x][y]);
        }
    }
    return colors;
}

void RenderColors(color_vec colors, size_noise width, size_noise height) {
    for (size_noise x = 0; x < width; x++) {
        for (size_noise y = 0; y < height; y++) {
            DrawRectangle(x * RENDER_SCALE, y * RENDER_SCALE, RENDER_SCALE, RENDER_SCALE, colors[x][y]);
        }
    }
}

void DrawLoop()
{
    SimplexNoiseStrategy simplexStrategy;

    NoiseGenerator noiseGenerator = NoiseGenerator(256, 256, &simplexStrategy);

    Noise noise = noiseGenerator.GenerateNoise();

    color_vec colors = GenerateColors(noise);


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            RenderColors(colors,noise.GetWidth(), noise.GetHeight());
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
