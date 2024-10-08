#include "raylib.h"
#include <cmath>

constexpr auto SCREEN_WIDTH  = 1600;
constexpr auto SCREEN_HEIGHT = 900;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Visualizing Vector2");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        
    }

    CloseWindow();
    return 0;
}
