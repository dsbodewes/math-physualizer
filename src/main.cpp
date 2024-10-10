// main.cpp
#include "raylib.h"
#include "SceneManager.h"
#include "MenuScene.h"
#include "SpaceshipScene.h"
#include "PendulumScene.h"

int main() {
    // Initialize Raylib window
    const int screenWidth = 1600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Math-Visualization");

    SetTargetFPS(60);

    // Create the scene manager and load the MenuScene
    SceneManager sceneManager;
    sceneManager.ChangeScene(new MenuScene());

    // Main game loop
    while (!WindowShouldClose()) {
        // Update and draw the current scene
        sceneManager.Update();

        BeginDrawing();
        ClearBackground(SKYBLUE);
        sceneManager.Draw();
        EndDrawing();

        // Scene switching logic
        if (IsKeyPressed(KEY_ONE)) {
            sceneManager.ChangeScene(new SpaceshipScene());
        }
        if (IsKeyPressed(KEY_TWO)) {
            sceneManager.ChangeScene(new PendulumScene());
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            sceneManager.ChangeScene(new MenuScene());
        }
    }

    // Close window and clean up
    CloseWindow();
    return 0;
}
