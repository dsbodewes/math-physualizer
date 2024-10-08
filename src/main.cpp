#include "raylib.h"
#include "Spaceship.h"



int main(){
    // Initialize Raylib window
    const int screenWidth = 1600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Spaceship!");

    // Create a spaceship
    Spaceship spaceship = Spaceship({screenWidth / 2.0f, screenHeight / 2.0}, 200.0f);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()){
        spaceship.Update();

        BeginDrawing();
        ClearBackground(BLACK);
        spaceship.Draw();
        EndDrawing();
    }

    // Close window and clean up
    CloseWindow();
    return 0;
}
