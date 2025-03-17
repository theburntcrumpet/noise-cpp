#include <raylib.h>
#include <vector>
#include "include/Noise.h"
#include "include/NoiseGenerator.h"
#include "include/PerlinNoiseStrategy.h"
#include "include/WindowConsts.h"

typedef std::vector<std::vector<Color>> color_vec;

void HandleInit()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(TARGET_FPS);
}

Color GetColorForValue(double n) {
    unsigned char r = static_cast<unsigned char>(std::max(0.0, 255 * (n - 0.5) * 2));
    unsigned char g = static_cast<unsigned char>(std::max(0.0, 255 * (1 - std::abs(n - 0.5) * 2)));
    unsigned char b = static_cast<unsigned char>(std::max(0.0, 255 * (0.5 - n) * 2));
    return (Color){ r, g, b, 255 };
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

Noise GenerateRandomNoise(NoiseGenerator noiseGenerator) {
    return noiseGenerator.GenerateNoise(GetRandomValue(0, 1000));
}

void DrawLoop()
{
    PerlinNoiseStrategy perlinStrategy;

    NoiseGenerator noiseGenerator = NoiseGenerator(256, 256, &perlinStrategy);

    Noise noise = noiseGenerator.GenerateNoise(10);

    color_vec colors = GenerateColors(noise);

    bool hasNoiseChanged = true;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            if (IsKeyPressed(KEY_SPACE)) {
                noise = GenerateRandomNoise(noiseGenerator);
                colors = GenerateColors(noise);
                hasNoiseChanged = true;
            }
            if(hasNoiseChanged) {
                ClearBackground(BLACK);
                RenderColors(colors,noise.GetWidth(), noise.GetHeight());
                hasNoiseChanged = false;
            }
            
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
